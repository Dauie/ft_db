#include "ft_db.h"

int			db_fillnode(t_dbnode *t_tree, t_dbnfo *db, FILE *p_file)
{
	t_dbnfo		file;
	char		tmp[2048];
	char		**value;

	fscanf(p_file, "%s", tmp);
	if (!(file.args = db_strsplit(tmp, '\n')))
		return (-1);
	if (isdigit(file.args[0][0]))
		file.nval = atoi(file.args[0]);
	if (isalpha(file.args[1][0]))
		strcpy(file.tbl_name, file.args[1]);
	if (isdigit(file.args[2][0]))
		file.ctime = atoi(file.args[2]);
	if (isdigit(file.args[3][0]))
		time(&file.agtime);
	int i = 3;
	while (file.args[++i])
	{
		value = db_strsplit(file.args[i], ',');
		strcpy(file.key_name, value[0]);
		file.val = db_tbldup(&value[1], db_tbllen(&value[1]));
	}

	return (0);
}
/*Filling the tree by going through db->args (table file list)
 * and filling a node with each table file. (.tbl) */
int			db_filltree(t_dbnode *t_tree, t_dbnfo *db)
{
	int i = -1;
	FILE *p_file;
	while (db->args[++i])
	{
		if (!(p_file = fopen(db->args[i], "r")))
		{
			printf("FT_DB ERROR: %s is missing!", db->args[i]);
			return (-1);
		}
		db_fillnode(t_tree, db, p_file);
		fclose(p_file);
	}
	return (0);
}

/*This function will fill in the t_tree with the metadata stored in db->args
 * then store the table file name list */
int			db_parsedbfile(t_dbnode *t_tree, t_dbnfo *db)
{
	char **tmp;

	if (isdigit(db->args[0][0]))
		t_tree->tblamt = atoi(db->args[0]);
	tmp = db->args;
	/*change 1 dependant on how many if's above for metadata*/
	if (!(db->args = db_tbldup(&db->args[1], t_tree->tblamt)))
		return (-1);
	db_tbldel(tmp);
	return (0);
}
/* If the rtt.db file is found it will be read into tmp, then
 * it will be passed to "db_parsedbfile" after we will have the table file list.
 * With this list we will build the tree, filling in each node with the
 * information from a table file.*/
int			db_populatedb(t_dbnode *t_tree, t_dbnfo *db, FILE *p_file)
{
	char	tmp[2048];		/*Need to define a max file size*/

	/*1st Line # of members*/
	
	fscanf(p_file, "%s", tmp);
	db->args = db_strsplit(tmp, '\n');
	db_parsedbfile(t_tree, db);
	db_filltree(t_tree, db);
	return (0);
}


/*Looks for a rtt.db file. If found it loads the file else it will create a
 * fresh copy of the rtt.db and fill it with initial information
 * Then it will populate the t_tree with the */
t_dbnode		*db_loaddatabase(t_dbnfo *db)
{
	t_dbnode	*t_tree;
	FILE		*p_file;

	t_tree = NULL;
	if (!(p_file = fopen( "rtt.db", "r")))
	{
		if (!(p_file = fopen("rtt.db", "ab")))
			return (NULL);
		fwrite("0\n0\n0\nNA", 8, 1, p_file);
		fclose(p_file);
		p_file = NULL;
	}
	if (p_file)
	{
		db_populatedb(t_tree, db, p_file);
		fclose(p_file);
		return (t_tree);
	}
	else
		db_addtnoden(&t_tree, db);
	return(t_tree);
}

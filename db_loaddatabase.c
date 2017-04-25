#include "ft_db.h"

/*Filling the tree by going through db->args (table file list)
 * and filling a node with each table file. (.tbl) */
void			db_filltree(t_dbnode *t_tree, t_dbnfo *db)
{

}

/*This function will fill in the t_tree with the metadata stored in db->args
 * then store the table file name list */
void			db_parsedbfile(t_dbnode *t_tree, t_dbnfo *db)
{
	char **tmp;

	if (isdigit(db->args[0][0]))
		t_tree->tblamt = atoi(db->args[0]);
	tmp = db->args;
	/*change 1 dependant on how many if's above for metadata*/
	db->args = db_tbldup(&db->args[1], t_tree->tblamt);
	db_tbldel(tmp);
}
/* If the rtt.db file is found it will be read into tmp, then
 * it will be passed to "db_parsedbfile" after we will have the table file list.
 * With this list we will build the tree, filling in each node with the
 * information from a table file.*/
void			db_populatedb(t_dbnode *t_tree, t_dbnfo *db, FILE *p_file)
{
	char	tmp[2048];		/*Need to define a max file size*/

	/*1st Line # of members*/
	
	fscanf(p_file, "%s", tmp);
	db->args = db_strsplit(tmp, '\n');
	db_parsedbfile(t_tree, db);
	db_filltree(t_tree, db);
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

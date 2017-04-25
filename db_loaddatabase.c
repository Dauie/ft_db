#include "ft_db.h"

void			db_populatedb(t_dbnode *t_tree,/* t_dbnfo *db,*/ FILE *p_file)
{
	char	tmp[MXNAMLEN];

	/*1st Line # of members*/
	
	fscanf(p_file, "%s", tmp);
	t_tree->tblamt = atoi(tmp);
	fscanf(p_file, "%s", tmp);
	t_tree->tbl_ctime = atoi(tmp);
	fscanf(p_file, "%s", tmp);
	t_tree->tbl_mtime = atoi(tmp);
	fscanf(p_file, "%s", t_tree->lmmbr);
	/*int i = -1;
	
	while(fscanf() )
	{	
		
		fscanf(p_file, "%s", t_tree->args[++i])
			;
	}
	while (tmp);*/
}

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
		db_populatedb(t_tree,/* db,*/ p_file);
		fclose(p_file);
		return (t_tree);
	}
	else
		db_addtnoden(&t_tree, db);
	return(t_tree);
}

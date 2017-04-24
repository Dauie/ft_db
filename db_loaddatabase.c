#include "ft_db.h"

void			db_populatedb(t_dbnode *t_tree, t_dbnfo *db, FILE *p_file)
{
	/*1st Line # of members*/
	fscanf(p_file, "%s", db->tblnum);
	/*DB Creation Time*/
	fscanf(p_file, "%s", db-> );

}

t_dbnode		*db_loaddatabase(t_dbnfo *db)
{
	t_dbnode	*t_tree;
	FILE		*p_file;

	if (!(t_tree = (t_dbnode *)malloc(sizeof(t_dbnode))))
		return (NULL);
	p_file = fopen( "rickytickytappy.db", "r");
	if (!(t_tree->entries = db_memalloc(sizeof(t_enode))))
			return (NULL);
	db_initenode(&t_tree->entries);
	if (p_file)
	{
		db_populatedb(t_tree, db, p_file);
		fclose(p_file);
		return (t_tree);
	}
	else
	{
		strcpy(t_tree->tbl_name, db->tbl_nam);
		time(&t_tree->tbl_ctime);
		time(&t_tree->tbl_mtime);
		
		strcpy(t_tree->entries->ename, db->key_nam);
		time(&t_tree->entries->emodtime);
		time(&t_tree->entries->ecretime);
		t_tree->entries->cmembr = db->val;
	}
	return(t_tree);
}

#include "ft_db.h"

void		db_populatedb(t_dbnode **t_tree, t_dbnfo *db, FILE *p_file)
{
	fscanf(p_file, "%s %s/n", (*t_tree)->tbl_name), (*t_tree)->entries->ename;
}

t_dbnode	*db_loaddatabase(t_dbnfo *db)
{
	t_dbnode *t_tree;
	FILE *p_file;

	if (!(t_tree = (t_dbnode *)malloc(sizeof(t_dbnode))))
		return (NULL);
	p_file = fopen( "rickytickytappy.db", "r");
	if (p_file)
	{
		db_populatedb(&t_tree, db, p_file);
		fclose(p_file);
		time(&t_tree->tbl_ctime);
		time(&t_tree->tbl_mtime);
		return (t_tree);
	}
	else
	{
		strcpy(t_tree->tbl_name, db->tbl_nam);
		time(&t_tree->tbl_ctime);
		time(&t_tree->tbl_mtime);
		if (!(t_tree->entries = db_memalloc(sizeof(t_enode))))
			return (NULL);
		db_initenode(&t_tree->entries);
		strcpy(t_tree->entries->ename, db->key_nam);
		time(&t_tree->entries->emodtime);
		time(&t_tree->entries->ecretime);
		t_tree->entries->cmembr = db->val;
		db_savedb(db, t_tree);
	}
	return(t_tree);
}

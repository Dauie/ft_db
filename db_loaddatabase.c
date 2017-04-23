#include "ft_db.h"

t_dbnode	*db_loaddatabase(t_dbnfo *db)
{
	t_dbnode *t_tree;
	FILE *p_file;

	if (!(t_tree = (t_dbnode *)malloc(sizeof(t_dbnode))))
		return (NULL);
	p_file = fopen( "rickytickytappy.db", "r");
	if (p_file)
	{
		db_populatedb();
		fclose(p_file);
		return (t_tree);
	}
	else
	{
		strcpy(t_tree->tbl_name, db.tbl_nam);
		time(&t_tree->tbl_ctime);
		time(&t_tree->tbl_mtime);
		if (!(db->entries = db_memalloc(sizeof(db_enode))))
			return (NULL);
		db_initenode(&db->entries);
		strcpy(db->entries->ename, db->keynam);
		time(&entries->emodtime);
		time(&entries->ecretime);
		entries->cmber = db->val;
	}
	return(t_tree);
}

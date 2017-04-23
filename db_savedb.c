#include "ft_db.h"

/*Saves each table name*/
void	db_savedb(t_dbnode **tree)
{
	
}

/*Saves the table's entry names*/
void	db_savetbl(t_dbnode **t_tree, char *tbl_name)
{
	static int *save_tbl_name;

	save_tbl_name = strndup(tbl_name, MXNAMLEN);
}

/*Saves the entry's values*/
void	db_saveentry(t_dbnode *t_tree, char *ename)
{
	static char *save_ename;
	static char *save_cmembr;
	static int save_nmembr;
	static time_t save_ecretime;
	static time_t save_emodtime;
	static t_enode *save_left;
	static t_enode *save_right;

	save_ename = strndup(ename, MXNAMLEN);
	save_cmembr = strdup(t_tree->entries->cmembr);
	save_nmembr = atoi(strdup(itoa(t_tree->entries->nmembr)));
	save_ecretime = t_tree->entries->ecretime;
	save_emodtime = t_tree->entries->emodtime;
	save_left = t_tree->entries->left;
	save_left = t_tree->entries->right;
}

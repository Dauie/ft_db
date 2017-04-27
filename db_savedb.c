#include "ft_db.h"

/*Saves each table name*/
/*
void	db_savedb(t_tnode **tree)
{
	;
}
*/
/*Saves the table's entry names*/
/*
void	db_savetbl(t_tnode **t_tree, char *tbl_name)
{
	;
}
*/
/*Saves the entry's values*/

void	db_saveentry(t_enode *entry, FILE *f_save)
{
	fprintf(f_save, "%s\n", entry->ename);
	int i = -1;
	while (entry->cmembr[++i])
		fprintf(f_save, "%s\n", entry->cmembr[i]);
}

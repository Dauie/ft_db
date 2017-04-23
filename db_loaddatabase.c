#include "ft_db.h"

t_dbnode	*db_loaddatabase(t_dbnfo db)
{
	t_dbnode *tree;
	FILE *p_file;

	if (!(tree = (t_dbnode *)malloc(sizeof(t_dbnode))))
		return (NULL);
	if (!(p_file = fopen( "rickytickytappy.db", "r")))
	{
		tree.tblnam = NULL;
		tree.tbl_ctime = 0;
		return (tree);
	}
	else
	{
		
	}
	return(tree);
}

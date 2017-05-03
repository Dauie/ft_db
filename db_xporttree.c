#include "ft_db.h"

void	db_xporttree(t_tnode *t_tree)
{
	//char c;
	//struct stat st = {0};

	if (!t_tree)
		return ;
	if (t_tree->left)
		db_xporttree(t_tree->left);
	/*while((c = getc("rtt.db")))
		putchar(c);
	if (stat("userdefined/directory", &st) == -1)
		mkdir("userdefined/directory");
	*/
	if (t_tree->right)
		db_xporttree(t_tree->right);
}

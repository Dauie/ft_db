#include "ft_db.h"

void		db_xportentries(t_enode *e_tree, char *tbl_name, FILE *p_xprt)
{
	size_t i;

	i = -1;
	if (!e_tree)
		return ;
	if (e_tree->left)
		db_xportentries(e_tree->left, tbl_name, p_xprt);
	fputs("\"",p_xprt );
	fputs(tbl_name, p_xprt);
	fputs("\"",p_xprt );
	fputs("\"",p_xprt );
	fputs(e_tree->ename, p_xprt);
	fputs("\"",p_xprt );
	fputs(",",p_xprt);
	while (e_tree->cmembr[++i])
	{
		fputs("\"",p_xprt );
		fputs(e_tree->cmembr[i], p_xprt);
		fputs("\"",p_xprt );
		fputs(",", p_xprt);
	}
	fputs("\n", p_xprt);
	if (e_tree->right)
		db_xportentries(e_tree->right, tbl_name, p_xprt);
}

void		db_xporttbls(t_tnode *t_tree, t_dbnfo *info, FILE *p_xprt)
{
	if (!t_tree)
		return ;
	if (t_tree->left)
		db_xporttbls(t_tree->left, info, p_xprt);
	db_xportentries(t_tree->entries,t_tree->tbl_name, p_xprt);
	if (t_tree->right)
		db_xporttbls(t_tree->right, info, p_xprt);
}

void		db_xportdb(t_tnode *t_tree, t_dbnfo *info)
{
	FILE	*p_xprt;

	if (!(p_xprt = fopen(info->tbl_name, "wb+")))
	{
		printf("%s: issues exporting db to: %s",G_TSYM, info->tbl_name);
		return ;
	}
	db_xporttbls(t_tree, info, p_xprt);
	fclose(p_xprt);
}


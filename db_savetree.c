#include "ft_db.h"

void	db_savettree(t_tnode *t_tree)
{
	if (!t_tree)
		return ;
	if (t_tree->left == NULL && t_tree->right == NULL)
	{
		FILE *f_save;
		if (!(f_save = fopen("tinyrick.txt.", "w")))
			return ;
		fprintf(f_save, "%s\n", t_tree->tbl_name);
		fclose(f_save);
		return ;
	}
	db_savettree(t_tree->left);
	db_savettree(t_tree->right);
}

void	db_savettreeval(t_tnode *t_tree)
{
	if (!t_tree)
		return ;
	if (t_tree->left == NULL && t_tree->right == NULL)
	{
		FILE *f_save;
		if (!(f_save = fopen("tinyrick.txt.", "w")))
			return ;
		fprintf(f_save, "%s\n", t_tree->tbl_name);
		db_saveentry(t_tree->entries, *f_save);
		fclose(f_save);
	}
	db_savettreeval(t_tree->left);
	db_savettreeval(t_tree->right);
}

void	db_revsavettree(t_tnode *t_tree)
{
	if (!t_tree)
		return ;
	if (t_tree->left == NULL && t_tree->right == NULL)
	{
		FILE *f_save;
		if (!(f_save = fopen("tinyrick.txt.", "w")))
			return ;
		fprintf(f_save, "%s\n", t_tree->tbl_name);
		fclose(f_save);
		return ;
	}
	db_revsavettree(t_tree->right);
	db_revsavettree(t_tree->left);
}

void	db_saveetree(t_enode *e_tree)
{
	if (!e_tree)
		return ;
	if (e_tree->left == NULL && e_tree->right == NULL)
	{
		FILE *f_save;
		if (!(f_save = fopen("tinyrick.txt.", "w")))
			return ;
		fprintf(f_save, "%s\n", e_tree->ename);
		fclose(f_save);
		return ;
	}
	db_saveetree(e_tree->left);
	db_saveetree(e_tree->right);
}

void	db_revsaveetree(t_enode *e_tree)
{
	if (!e_tree)
		return ;
	if (e_tree->left == NULL && e_tree->right == NULL)
	{
		FILE *f_save;
		if (!(f_save = fopen("tinyrick.txt.", "w")))
			return ;
		fprintf(f_save, "%s\n", e_tree->ename);
		fclose(f_save);
		return ;
	}
	db_revsaveetree(e_tree->right);
	db_revsaveetree(e_tree->left);
}

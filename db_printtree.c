/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_printtree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:08:20 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/27 14:36:45 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

/*void 	db_printttree(t_tnode *t_tree)
{
	if (!t_tree)
		return ;
	if (t_tree->left == NULL && t_tree->right == NULL)
	{
		printf("%s\n", t_tree->tbl_name);
		return ;
	}
	db_printttree(t_tree->left);
	db_printttree(t_tree->right);
}*/

void 	db_printttree(t_tnode *t_tree)
{
	if (!t_tree)
		return ;
	if (t_tree->left)
		db_printttree(t_tree->left);
	printf("%s\n", t_tree->tbl_name);
	if (t_tree->right)
		db_printttree(t_tree->right);
}

/*void 	db_printttreeval(t_tnode *t_tree)
{
	if (!t_tree)
		return ;
	if (t_tree->left == NULL && t_tree->right == NULL)
	{
		printf("%s\n", t_tree->tbl_name);
		db_printentry(t_tree->entries);
	}
	db_printttreeval(t_tree->left);
	db_printttreeval(t_tree->right);
}*/

void 	db_printttreeval(t_tnode *t_tree)
{
	if (!t_tree)
		return ;
	if (t_tree->left)
		db_printttree(t_tree->left);
	printf("%s\n", t_tree->tbl_name);
	db_printentry(t_tree->entries);
	if (t_tree->right)
		db_printttree(t_tree->right);
}

/*void 	db_revprintttree(t_tnode *t_tree)
{
	if (!t_tree)
		return ;
	if (t_tree->left == NULL  && t_tree->right == NULL)
	{
		printf("%s\n", t_tree->tbl_name);
		return ;
	}
	db_revprintttree(t_tree->left);
	db_revprintttree(t_tree->right);
}*/
void 	db_revprintttree(t_tnode *t_tree)
{
	if (!t_tree)
		return ;
	if (t_tree->right)
		db_revprintttree(t_tree->right);
	printf("%s\n", t_tree->tbl_name);
	if (t_tree->left)
		db_revprintttree(t_tree->left);
}

/*void 	db_printetree(t_enode *e_tree)
{
	if (!e_tree)
		return ;
	if (e_tree->left == NULL && e_tree->right == NULL)
	{
		printf("%s\n", e_tree->ename);
		return ;
	}
	db_printetree(e_tree->left);
	db_printetree(e_tree->right);
}*/
void 	db_printetree(t_enode *e_tree)
{
	if (!e_tree)
		return ;
	if (e_tree->left)
		db_printetree(e_tree->left);
	printf("%s\n", e_tree->ename);
	if (e_tree->right)
		db_printetree(e_tree->right);
}

/*void 	db_revprintetree(t_enode *e_tree)
{
	if (!e_tree)
		return ;
	if (e_tree->left == NULL && e_tree->right == NULL)
	{
		printf("%s\n", e_tree->ename);
		return ;
	}
	db_revprintetree(e_tree->left);
	db_revprintetree(e_tree->right);
}*/
void 	db_revprintetree(t_enode *e_tree)
{
	if (!e_tree)
		return ;
	if (e_tree->right)
		db_revprintetree(e_tree->right);
	printf("%s\n", e_tree->ename);
	if (e_tree->left)
		db_revprintetree(e_tree->left);
}

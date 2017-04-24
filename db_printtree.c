/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_printtree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:08:20 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/24 12:35:42 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void 	db_printttree(t_dbnode *t_tree)
{
	if (!t_tree)
		return ;
	if (t_tree->left)
		ls_printtree(t_tree->left);
	printf("%s\n", t_tree->tbl_name);
	if (t_tree->right)
		ls_printtree(t_tree->right);
}

void 	db_revprintttree(t_dbnode *t_tree)
{
	if (!t_tree)
		return ;
	if (t_tree->right)
		ls_revprinttree(t_tree->right);
	printf("%s\n", t_tree->tbl_name);
	if (t_tree->left)
		ls_revprinttree(t_tree->left);
}

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

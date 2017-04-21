/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_printtree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:08:20 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/20 18:46:53 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void 	ls_printtree(t_dbnode *tree)
{
	if (!tree)
		return ;
	if (tree->left)
		ls_printtree(tree->left);
	printf("%s\t", tree->tbl_name);
	if (tree->right)
		ls_printtree(tree->right);
}

void 	ls_revprinttree(t_dbnode *tree)
{
	if (!tree)
		return ;
	if (tree->right)
		ls_revprinttree(tree->right);
	printf("%s  ", tree->tbl_name);
	if (tree->left)
		ls_revprinttree(tree->left);
}

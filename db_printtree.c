/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_printtree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:08:20 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/19 21:00:21 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void 	ls_printtree(t_dbnode *tree)
{
	if (!tree)
		return ;
	if (tree->left)
		ls_printtree(tree->left);
	printf("%s\t", tree->name);
	if (tree->right)
		ls_printtree(tree->right);
}

void 	ls_revprinttree(t_dbnode *tree)
{
	if (!tree)
		return ;
	if (tree->right)
		ls_revprinttree(tree->right);
	printf("%s  ", tree->name);
	if (tree->left)
		ls_revprinttree(tree->left);
}

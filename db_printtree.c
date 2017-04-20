/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printtree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:08:20 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/18 13:38:38 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

void 	ls_printtree(t_node *tree)
{
	if (!tree)
		return ;
	if (tree->left)
		ls_printtree(tree->left);
	ft_printf("%s\t", tree->name);
	if (tree->right)
		ls_printtree(tree->right);
}

void 	ls_revprinttree(t_node *tree)
{
	if (!tree)
		return ;
	if (tree->right)
		ls_revprinttree(tree->right);
	ft_printf("%s  ", tree->name);
	if (tree->left)
		ls_revprinttree(tree->left);
}

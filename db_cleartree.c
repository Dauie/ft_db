/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_cleartree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:07:26 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/24 16:58:49 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void ls_cleartree(t_tnode **tree)
{
	t_tnode		*tmp;

	tmp = *tree;
	if (!tree)
		return ;
	if (tmp->left)
		ls_cleartree(&tmp->left);
	if (tmp->right)
		ls_cleartree(&tmp->right);
	free(tmp);
	tree = NULL;
}

void ls_clearetree(t_tnode **tree)
{
	t_tnode		*tmp;

	tmp = *tree;
	if (!tree)
		return ;
	if (tmp->left)
		ls_clearetree(&tmp->left);
	if (tmp->right)
		ls_clearetree(&tmp->right);
	free(tmp);
	tree = NULL;
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_treesearch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:08:42 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/26 17:19:10 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		db_search_tnam(t_tnode *tree, char *name)
{
	t_tnode	*tmp;

	tmp = tree;
	while (tmp)
	{
		if (name == tmp->tbl_name)
			return (1);
		if (strcmp(name, tmp->tbl_name) > 0)
			tmp = tmp->right;
		else
			tmp = tmp->left;
	}
	return (0);
}

t_tnode		*db_searchtnode(t_tnode *t_tree, t_dbnfo *info)
{
	t_tnode *tmp;

	tmp = t_tree;
	if (*info->tbl_name == '\0')
		return (NULL);
	if (strcmp(info->tbl_name,tmp->tbl_name) == 0)
		return (tmp);
	if (strcmp(info->tbl_name, tmp->tbl_name) > 0 && tmp->right != NULL)
		db_searchtnode(tmp->right, info);
	else if (tmp->left != NULL)
		db_searchtnode(tmp->left, info);
	return (NULL);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_treesearch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:08:42 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/27 14:40:36 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

t_tnode		*db_searchtnode(t_tnode *t_tree, t_dbnfo *info)
{
	t_tnode *tmp;

	tmp = t_tree;
	while (tmp)
	{
		if (strcmp(info->tbl_name, tmp->tbl_name) == 0)
			return (tmp);
		if (strcmp(info->tbl_name, tmp->tbl_name) > 0)
				tmp = tmp->right;
		else
			tmp = tmp->left;
	}
	return (NULL);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_treesearch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:08:42 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/22 13:31:17 by rlutt            ###   ########.fr       */
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

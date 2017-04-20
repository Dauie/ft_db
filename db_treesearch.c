/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_treesearch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:08:42 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/19 20:59:37 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		ls_treesearch(t_dbnode *tree, char *name)
{
	t_dbnode	*tmp;

	tmp = tree;
	while (tmp)
	{
		if (name == tmp->name)
			return (1);
		if (strcmp(name, tmp->name) > 0)
			tmp = tmp->right;
		else
			tmp = tmp->left;
	}
	return (0);
}

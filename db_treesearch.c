/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_treesearch.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:08:42 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/21 15:00:32 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		ls_treesearch(t_dbnode *tree, char *name)
{
	t_dbnode	*tmp;

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

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

t_tnode		*db_searchtnode(t_node *t_tree, t_dbnfo *db)
{
	search through entire node set;
	if specified node does not exist, create it;
	add node potentially might need to return something;

	t_tnode *tmp;

	tmp = t_tree;
	if (!name)
		return (NULL);
	if (name == tmp->tbl_name)
		return (tmp->);
	if (strcmp(name, tmp->tbl_name) > 0 && tmp->right != NULL)
		return (db_searchtnode(tmp->right, name))
	else if (tmp->left != NULL)
		return (db_searchtnode(tmp->left, name))
	else
		db_addtnoden(t_tree)
	return (0);
	/*t_tridbnode		tri;

	tri.ttmp = *t_tree;

	if (tri.ttmp)
	{
		while (tri.tmp)
		{
			tri.ntmp = tri.ttmp;

		}
	}*/
}

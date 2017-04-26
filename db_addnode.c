/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_addnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:00:51 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/25 18:50:20 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*42 - Robert Wyatt Lutt - ft_ls*/

#include "ft_db.h"

static t_tnode *prep_addtnode(t_dbnfo *db)
{
	t_tnode *elem;

	if (!(elem = (t_tnode *)db_memalloc(sizeof(t_tnode))))
		return (NULL);
	db_initdbnode(elem);
	strcpy(elem->tbl_name, db->tbl_name);
	return (elem);
}

void 		db_addtnoden(t_tnode **t_tree, t_dbnfo *db)
{
	t_tridbnode		tri;

	tri.ttmp = *t_tree;
	tri.elem = prep_addtnode(db);
	if (tri.ttmp)
	{
		while (tri.ttmp)
		{
			tri.ntmp = tri.ttmp;
			if (tri.ttmp && strcmp(tri.elem->tbl_name, tri.ttmp->tbl_name) < 0)
			{
				tri.ttmp = tri.ttmp->left;
				if (!tri.ttmp)
					tri.ntmp->left = tri.elem;
			}
			else
			{
				tri.ttmp = tri.ttmp->right;
				if (!tri.ttmp)
					tri.ntmp->right = tri.elem;
			}
		}
	}
	else
		*t_tree = tri.elem;
	if (db->mode == ADD_TBL)
		db->mode = NRML;
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_addnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:00:51 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/25 14:22:41 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*42 - Robert Wyatt Lutt - ft_ls*/

#include "ft_db.h"

static t_dbnode *prep_addtnode(t_dbnfo *db)
{
	t_dbnode *elem;

	if (!(elem = (t_dbnode *)db_memalloc(sizeof(t_dbnode))))
		return (NULL);
	db_initdbnode(elem);
	strcpy(elem->tbl_name, db->tbl_name);
	if (!(elem->entries = (t_enode *)db_memalloc(sizeof(t_enode))))
		return (NULL);
	strcpy(elem->entries->ename, db->key_nam);
	time(&elem->entries->emodtime);
	time(&elem->entries->ecretime);
	elem->entries->cmembr = db_tbldup(db->val, db->nval);
	return (elem);
}

void 		db_addtnoden(t_dbnode **t_tree, t_dbnfo *db)
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


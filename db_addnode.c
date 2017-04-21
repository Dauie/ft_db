/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_addnode.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:00:51 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/20 18:25:59 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*42 - Robert Wyatt Lutt - ft_ls*/

#include "ft_db.h"


int		ls_getmeta(t_dbnode *elem, char *name)
{

	return (1);
}

static t_dbnode *prep_addnode (char *name, int wght, t_dbnfo *db)
{
	t_dbnode *elem;

	if (!(elem = (t_dbnode *)malloc(sizeof(t_dbnode))))
		return (NULL);
	db_initnode(elem);
	elem->tbl_name = strdup(name);
	elem->wght = wght;
	return (elem);
}

void 		ls_addtnoden(t_dbnode **tree, char *name, char type, t_dbnfo *db)
{
	t_tridbnode		tri;

	tri.ttmp = *tree;
	tri.elem = prep_addnode(name, type, db);
	if (tri.ttmp)
	{
		while (tri.ttmp)
		{
			tri.ntmp = tri.ttmp;
			if (tri.ttmp && strcmp(name, tri.ttmp->tbl_name) < 0)
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
		*tree = tri.elem;
}

void 		ls_addtnodet(t_dbnode **tree, char *name, char type, t_dbnfo *db)
{
	t_tridbnode		tri;

	tri.ttmp = *tree;
	tri.elem = prep_addnode(name, type, db);
	if (tri.ttmp)
	{
		while (tri.ttmp)
		{
			tri.ntmp = tri.ttmp;
			if (tri.ttmp && tri.elem->data.tbl_ctime < tri.ttmp->data.tbl_ctime)
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
		*tree = tri.elem;
}

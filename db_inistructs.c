/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_inistructs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 20:54:58 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/21 17:22:57 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	db_initdbnfo(t_dbnfo *db)
{
	db->args = NULL;
	db->a_tbln = NULL;
	db->a_keyn = NULL;
	db->a_val = NULL;
	db->t_actn = false;
	db->n_actn = false;
	db->v_actn = false;
	db->mode = NRML;
}

void	db_initnode(t_dbnode *elem)
{
	elem->wght = 0;
	elem->tbl_ctime = 0;
	elem->tbl_mtime = NULL;
	elem->tbl = NULL;
	elem->left = NULL;
	elem->right = NULL;
	elem->tbl_name = NULL;
}

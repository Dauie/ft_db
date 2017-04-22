/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_inistructs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 20:54:58 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/22 11:10:09 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	db_initdbnfo(t_dbnfo *db)
{
	db->args = NULL;
	db->a_tblnam = NULL;
	db->a_keynam = NULL;
	db->a_val = NULL;
	db->tbln_act = false;
	db->val_act = false;
	db->nval_act = false;
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

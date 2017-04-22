/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_inistructs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 20:54:58 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/22 12:35:05 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	db_initdbnfo(t_dbnfo *db)
{
	db->args = NULL;
	db->agtime = 0;
	db->tblnam = NULL;
	db->keynam = NULL;
	db->val = NULL;
	db->tbln_act = false;
	db->key_act = false;
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

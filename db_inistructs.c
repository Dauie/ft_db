/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_inistructs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 20:54:58 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/26 18:17:32 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	db_initdbnfo(t_dbnfo *db)
{
	db->args = NULL;
	db->nargs = 0;
	db->mtime = 0;
	db->ctime = 0;
	bzero(db->tbl_name, MXNAMLEN);
	bzero(db->key_name, MXNAMLEN);
	db->val = NULL;
	db->nval = 0;
	db->tbln_act = false;
	db->key_act = false;
	db->val_act = false;
	db->nval_act = false;
	db->mode = NRML;
}

void	db_inittnode(t_tnode *elem)
{
	elem->tblamt = 0;
	bzero(elem->tbl_name, MXNAMLEN);
	bzero(elem->lmmbr, MXNAMLEN);
	elem->entries = NULL;
	elem->left = NULL;
	elem->right = NULL;
}

void	db_initenode(t_enode *entry)
{
	bzero(entry->ename, MXNAMLEN);
	entry->emtime = 0;
	entry->ectime = 0;
	entry->cmembr = NULL;
	entry->nmembr = NULL;
	entry->left = NULL;
	entry->right = NULL;
}

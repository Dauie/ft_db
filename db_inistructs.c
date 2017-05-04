/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_inistructs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 20:54:58 by rlutt             #+#    #+#             */
/*   Updated: 2017/05/04 11:27:40 by rlutt            ###   ########.fr       */
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

void	db_cleandbnfo(t_dbnfo *db)
{
	if (db->args)
		db_tbldel(db->args);
	if (db->val)
		db_tbldel(db->val);

}

void	db_inittnode(t_tnode *elem)
{
	elem->tblamt = 0;
	elem->ctime = 0;
	elem->mtime = 0;
	bzero(elem->tbl_name, MXNAMLEN);
	elem->entries = NULL;
	elem->left = NULL;
	elem->right = NULL;
}

void	db_initenode(t_enode *entry)
{
	bzero(entry->ename, MXNAMLEN);
	entry->ctime = 0;
	entry->mtime = 0;
	entry->cmembr = NULL;
	entry->left = NULL;
	entry->right = NULL;
}

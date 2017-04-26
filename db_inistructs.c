/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_inistructs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 20:54:58 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/25 15:41:02 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	db_initdbnfo(t_dbnfo *db)
{
	db->args = NULL;
	bzero(db->tbl_name, MXNAMLEN);
	bzero(db->key_name, MXNAMLEN);
	db->agtime = 0;
	db->val = NULL;
	db->nval = 0;
	db->tbln_act = false;
	db->key_act = false;
	db->val_act = false;
	db->nval_act = false;
	db->mode = NRML;
}

void	db_initdbnode(t_tnode *elem)
{
	elem->left = NULL;
	elem->right = NULL;
}

void	db_initenode(t_enode *entry)
{
	entry->left = NULL;
	entry->right = NULL;
	entry->emodtime = 0;
	entry->cmembr = NULL;
	entry->nmembr = 0;
}

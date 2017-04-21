/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_inistructs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 20:54:58 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/21 12:28:51 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	db_initdbnfo(t_dbnfo *db)
{
	db->addtbl_f = false;
	db->deltbl_f = false;
	db->addntry_f = false;
	db->delntry_f = false;
	db->editntry_f = false;
}


void	db_initnode(t_dbnode *elem)
{
	elem->wght = 0;
	elem->data.tbl_ctime = 0;
	elem->data.tbl_mtime = NULL;
	elem->data.bse_tbl = NULL;
	elem->data.num_tbl = NULL;
	elem->left = NULL;
	elem->right = NULL;
	elem->tbl_name = NULL;
}

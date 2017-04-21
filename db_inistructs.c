/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_inistructs.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 20:54:58 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/21 16:08:20 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	db_initdbnfo(t_dbnfo *db)
{
	db->args = NULL;
	db->a_nam = NULL;
	db->a_val = NULL;
	db->n_actn = false;
	db->v_actn = false;
	db->action = NRML;
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

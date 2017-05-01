/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_deldb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 13:01:36 by rlutt             #+#    #+#             */
/*   Updated: 2017/05/01 13:23:43 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void		db_delvalue(t_tnode *t_tree, t_dbnfo *info)
{
	/*tbldel the old tbl*/
	t_tnode *table;
	t_enode *entry;

	table = NULL;
	entry = NULL;
	if (!(table = db_searchtnode(t_tree, info)))
	{
		printf("ft_db: ERROR. Table not found.");
		return ;
	}
	if (!(entry = db_searchenode(table->entries, info)))
	{
		printf("ft_db: ERROR. Entry not found.");
		return ;
	}
	db_tblrmline(entry->cmembr, *info->val, db_tbllen(entry->cmembr));
}

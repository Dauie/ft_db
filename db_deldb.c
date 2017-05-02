/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_deldb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/01 13:01:36 by rlutt             #+#    #+#             */
/*   Updated: 2017/05/01 18:15:31 by rlutt            ###   ########.fr       */
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
		printf("ft_db: ERROR. Table not found.\n");
		return ;
	}
	if (!(entry = db_searchenode(table->entries, info)))
	{
		printf("ft_db: ERROR. Entry not found.\n");
		return ;
	}
	entry->cmembr = db_tblrmline(entry->cmembr, *info->val, db_tbllen(entry->cmembr));
}

void		db_deltbl(t_dbnfo *info)
{
	int		ret;
	char	*path;
	char	*filename;
	
	path = NULL;
	filename = NULL;
	if (!(filename = db_strjoin(info->tbl_name, ".tbl")))
		return ;
	if (!(path = db_strjoin("tbls/", filename)))
		return ;
	if ((ret = remove(path) == 0))
		printf("%s: %s has been deleted\n", G_TSYM, filename);
	else
		printf("%s: issues deleting %s\n", G_TSYM, filename);

	free(filename);
	free(path);
}


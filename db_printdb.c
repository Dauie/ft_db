/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_printdb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 19:40:14 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/27 19:41:58 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	db_printhelp(void)
{
	printf("ALL COMMANDS ARE ENTERED: ./ft_db -mode [table] [key] [value / new value ...]\n");
	printf("-_-_-_-_ Legend -_-_-_-_\n\n");
	printf("-ae :	add entry\n");
	printf("-ee :	edit entry\n");
	printf("-dt :	delete table\n");
	printf("-de :	delete entry\n");
	printf("-pd :	print entire DB\n");
	printf("-pt :	print table\n");
	printf("-ptm:	print table info\n");
	printf("-pe :	print entry\n");
	printf("-xt :	export table\n");
	printf("-xe :	export entry\n");
}

void	db_printdb(t_tnode *t_tree)
{
	if (!t_tree)
		return ;
	if (t_tree->left)
		db_printdb(t_tree->left);
	printf("Table: %s\n", t_tree->tbl_name);
	db_printetree(t_tree->entries);
	if (t_tree->right)
		db_printdb(t_tree->right);
}

void db_printtable(t_tnode *t_tree, t_dbnfo *info)
{
	t_tnode *node;

	node = NULL;
	if (!(node = db_searchtnode(t_tree, info)))
	{
		printf("ft_db: ERROR. Table not found.");
		return ;
	}
	printf("Table: %s\n", t_tree->tbl_name);
	db_printetree(t_tree->entries);
}

void	db_printtblmeta(t_tnode *t_tree, t_dbnfo *info)
{
		t_tnode *node;

	node = NULL;
	if (!(node = db_searchtnode(t_tree, info)))
	{
		printf("ft_db: ERROR. Table not found.");
		return ;
	}
	printf("Table: %s\n", t_tree->tbl_name);

	printf("table: %s", t_tree->tbl_name);
	printf("last entry modified: %s", t_tree->lmmbr);
}
/*Prints the table's entry names*/

void	db_printentrymeta(t_enode *entry)
{

	printf("entry Name: %s", entry->ename);
	printf("last Modified: %s\n", ctime(&entry->emtime));
	printf("Created: %s\n", ctime(&entry->ectime));
}
/*Prints the entry's values*/
void	db_printentry(t_enode *entry)
{
	printf("Entry: %s\n", entry->ename);
	int i = -1;
	while (entry->cmembr[++i])
		printf("%s |", entry->cmembr[i]);
	printf("\n");
}


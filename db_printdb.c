/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_printdb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 19:40:14 by rlutt             #+#    #+#             */
/*   Updated: 2017/05/03 17:24:13 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	db_printhelp(void)
{
	printf("./ft_db -mode [table] [key] [value / new value ...]\n");
	printf("%s	ZEN %s  DATA	%s\n\n", G_EDIV, G_TSYM, G_EDIV);
	printf("%s :	table symbol\n", G_TSYM);
	printf("%s :	entry symbol\n\n", G_ESYM);
	printf("-_-_-_-_ Legend -_-_-_-_\n\n");
	printf("-ae :	add entry\n");
	printf("-dt :	delete table\en");
	printf("-de :	delete entry\n");
	printf("-dv :	delete entry's value\en");
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
	printf("%s %s: %s\n",G_TLIN, G_TSYM, t_tree->tbl_name);
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
	printf("%s  : %s\n", G_TSYM, node->tbl_name);
	db_printetree(node->entries);
}

void	db_printtblmeta(t_tnode *t_tree, t_dbnfo *info)
{
	t_tnode *table;

	table = NULL;
	if (!(table = db_searchtnode(t_tree, info)))
	{
		printf("ft_db: ERROR. Table not found.");
		return ;
	}
	printf("%s: %s\n",G_TSYM, table->tbl_name);
	printf("created: %s", ctime(&table->ctime));
	printf("modified: %s", ctime(&table->ctime));
}


/*Prints the table's entry names*/
void	db_printentrymeta(t_enode *entry)
{
	printf("%s: %s", G_ESYM, entry->ename);
	printf("created: %s\n", ctime(&entry->ctime));
	printf("modified: %s\n", ctime(&entry->mtime));
}


/*Prints the entry's values*/
void	db_printentry(t_tnode *t_tree, t_dbnfo *info)
{
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
	printf("%s: %s\n", G_ESYM, entry->ename);
	int i = -1;
	while (entry->cmembr[++i])
		printf("%s %s", entry->cmembr[i], G_EDIV);
	printf("\n");
}


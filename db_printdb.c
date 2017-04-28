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
	printf("all examples: ./ft_db -mode [table] [key] [value / new value ...]\n");
	printf("-_-_-_- \033[01;31m\u0950  Legend \u0950\033[0m  -_-_-_\n");
	printf("|  \033[01;31m-ae\033[0m : add entry        |\n");
	printf("|  \033[01;31m-ee\033[0m : edit entry       |\n");
	printf("|  \033[01;31m-dt\033[0m : delete table     |\n");
	printf("|  \033[01;31m-de\033[0m : delete entry     |\n");
	printf("|  \033[01;31m-pd\033[0m : print entire DB  |\n");
	printf("|  \033[01;31m-pt\033[0m : print table      |\n");
	printf("|  \033[01;31m-ptm\033[0m: print table info |\n");
	printf("|  \033[01;31m-pe\033[0m : print entry      |\n");
	printf("|  \033[01;31m-xt\033[0m : export table     |\n");
	printf("|  \033[01;31m-xe\033[0m : export entry     |\n");
	printf("-_-_-_-_-_-_-_-_-_-_-_-_-_\n");
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


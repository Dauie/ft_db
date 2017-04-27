/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_printdb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 19:40:14 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/27 16:36:22 by rlutt            ###   ########.fr       */
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

/*Prints the meta data for the database*/
void	db_printdbmeta(t_tnode *t_tree)
{
	printf("%s", t_tree->tbl_name);
}

/*Prints each table name*/
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
/*prints a tables metadata*/
void	db_printtblmeta(t_tnode *t_tree)
{
	printf("Table: %s", t_tree->tbl_name);
	printf("Last entry modified: %s", t_tree->lmmbr);
}
/*Prints the table's entry names*/

/*prints a entry's metadata*/
void	db_printentrymeta(t_enode *entry)
{

	printf("Entry Name: %s", entry->ename);
	printf("Last Modified: %s\n", ctime(&entry->emtime));
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


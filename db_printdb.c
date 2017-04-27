/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_printdb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 19:40:14 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/26 18:22:35 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

/*Prints the meta data for the database*/
void	db_printdbmeta(t_tnode *t_tree)
{
	printf("%s", t_tree->tbl_name);
}

/*Prints each table name*/
void	db_printdb(t_tnode **t_tree)
{
	db_printttree(*t_tree);
}
/*prints a tables metadata*/
void	db_printtblmeta(t_tnode *t_tree)
{
	printf("Table: %s", t_tree->tbl_name);
	printf("Last entry modified: %s", t_tree->lmmbr);
}
/*Prints the table's entry names*/
void	db_printtbl(char *tbl_name, t_enode **e_tree)
{
	printf("Table: %s", tbl_name);
	db_printetree(*e_tree);
}
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
	printf("%s\n", entry->ename);
	int i = -1;
	while (entry->cmembr[++i])
		printf("%s\n", entry->cmembr[i]);
}


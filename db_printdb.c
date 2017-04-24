/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_printdb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 19:40:14 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/24 12:47:11 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

/*Prints the meta data for the database*/
void	db_printdbmeta(t_dbnode **tree)
{

}

/*Prints each table name*/
void	db_printdb(t_dbnode **t_tree)
{

}

/*prints a tables metadata*/
void	db_printtblmeta(t_dbnode **t_tree, char *tbl_name)
{
	
}
/*Prints the table's entry names*/
void	db_printtbl(t_dbnode **t_tree, char *tbl_name)
{
	printf("%s\n", tbl_name);
	db_printttree(*t_tree);
}
/*prints a entry's metadata*/
void	db_printentrymeta(t_enode *entry)
{
	printf("Entry Name: %s", entry->ename);
	printf("Last Modified: %s\n", ctime(&entry->emodtime));
	printf("Created: %s\n", ctime(&entry->ecretime));
}
/*Prints the entry's values*/
void	db_printentry(t_enode *entry)
{
	printf("%s", entry->ename);
	int i = -1;
	while (entry->cmembr[++i])
		printf("%s", entry->cmembr[i]);
}


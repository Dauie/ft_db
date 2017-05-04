/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_printdb.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 19:40:14 by rlutt             #+#    #+#             */
/*   Updated: 2017/05/04 12:54:35 by rlutt            ###   ########.fr       */
/*   Updated: 2017/05/01 14:37:33 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void	db_printhelp(void)
{
		printf("./ft_db -mode [table] [key] [value / new value ...]\n");
  	printf("	________________________________\n");
  	printf("	%s                               %s\n", G_DLIN, G_DLIN);
 	printf("	%s   \033[22;31m%s\033[0m      \033[01;31mZEN\033[0m \033[22;31m%s\033[0m  \033[01;31mDATA\033[0m      \033[22;31m%s\033[0m   %s\n", G_DLIN,  G_EDIV, G_TSYM, G_EDIV, G_DLIN);
 	printf("	%s                               %s\n", G_DLIN, G_DLIN);
 	printf("	%s  \033[22;31m%s\033[0m :	table symbol            %s\n", G_DLIN, G_TSYM, G_DLIN);
 	printf("	%s  \033[22;31m%s\033[0m :	entry symbol            %s\n", G_DLIN, G_ESYM, G_DLIN);
 	printf("	%s  \033[22;31m-_-_-_-_\033[0m \033[01;31mLegend\033[0m \033[22;31m_-_-_-_-\033[0m     %s\n", G_DLIN, G_DLIN);
  	printf("	%s                               %s\n", G_DLIN, G_DLIN);
 	printf("	%s  \033[22;31m-ae\033[0m :   add entry            %s\n", G_DLIN, G_DLIN);
 	printf("	%s  \033[22;31m-dt\033[0m :   delete table         %s\n", G_DLIN, G_DLIN);
 	printf("	%s  \033[22;31m-de\033[0m :   delete entry         %s\n", G_DLIN, G_DLIN);
 	printf("	%s  \033[22;31m-dv\033[0m :   delete entry's value %s\n", G_DLIN, G_DLIN);
 	printf("	%s  \033[22;31m-pd\033[0m :   print entire DB      %s\n", G_DLIN, G_DLIN);
 	printf("	%s  \033[22;31m-pt\033[0m :   print table          %s\n", G_DLIN, G_DLIN);
 	printf("	%s  \033[22;31m-ptm\033[0m:   print table info     %s\n", G_DLIN, G_DLIN);
 	printf("	%s  \033[22;31m-pe\033[0m :   print entry          %s\n", G_DLIN, G_DLIN);
 	printf("	%s  \033[22;31m-xt\033[0m :   export table         %s\n", G_DLIN, G_DLIN);
 	printf("	%s  \033[22;31m-xe\033[0m :   export entry         %s\n", G_DLIN, G_DLIN);
  	printf("	%s                               %s\n", G_DLIN, G_DLIN);
  	printf("	%s_______________________________%s\n", G_DLIN, G_DLIN);
}

void	db_printdb(t_tnode *t_tree)
{
	if (!t_tree)
		return ;
	if (t_tree->left)
		db_printdb(t_tree->left);
	printf("%s: %s\n", G_TSYM, t_tree->tbl_name);
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

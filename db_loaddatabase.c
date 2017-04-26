/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_loaddatabase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 20:07:04 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/25 20:35:58 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int			db_fillnode(t_tnode *t_tree, FILE *p_file)
{
	t_dbnfo		file;
	char		tmp[2048];
	char		**value;
	
	db_initdbnfo(&file);
	if (!(fscanf(p_file, "%s", tmp)))
		return (-1);
	file.nval = atoi(tmp);
	bzero(tmp, 2048);
	if (!(fscanf(p_file, "%s", tmp)))
		return (-1);
	file.ctime = atoi(tmp);
	bzero(tmp, 2048);
	if (!(fscanf(p_file, "%s", tmp)))
		return (-1);
	file.agtime = atoi(tmp);
	bzero(tmp, 2048);
	int i = file.nval;
	while (i-- > 0)
	{
		fscanf(p_file, "%s`", tmp);
		value = (char **)db_strsplit(tmp, ',');
		file.val = (char **)db_tbldup(&value[1], db_tbllen(&value[1]));
		/*db_tbldel(value)*/
		bzero(tmp, 2048);
		db_addenoden(&t_tree->entries, &file);
	}
	return (0);
}
/*Filling the tree by going through db->args (table file list)
 * and filling a node with each table file. (.tbl) */
int			db_filltree(t_tnode *t_tree, t_dbnfo *sort)
{
	int i = -1;
	FILE *p_file;
	while (sort->args[++i])
	{
		if (!(p_file = fopen(sort->args[i], "r")))
		{
			printf("FT_DB ERROR: %s is missing!", sort->args[i]);
			return (-1);
		}
		db_fillnode(t_tree, p_file);
		fclose(p_file);
	}
	return (0);
}

/*This function will fill in the t_tree with the metadata stored in db->args
 * then store the table file name list */
int				db_parsedbfile(t_tnode *t_tree, t_dbnfo *sort)
{
	char		**tmp;

	if (isdigit(sort->args[0][0]))
		t_tree->tblamt = atoi(sort->args[0]);
	tmp = sort->args;
	/*change 1 dependant on how many if's above for metadata*/
	if (!(sort->args = (char **)db_tbldup(&sort->args[2], t_tree->tblamt)))
		return (-1);
	db_tbldel(tmp);
	return (0);
}
/* If the rtt.db file is found it will be read into tmp, then
 * it will be passed to "db_parsedbfile" after we will have the table file list.
 * With this list we will build the tree, filling in each node with the
 * information from a table file.*/
int				db_populatedb(t_tnode *t_tree, FILE *p_file)
{
	t_dbnfo		sort;
	char		tmp[2048];		/*Need to define a max file size*/
	while (i > 0)
	{
		;
	}
	sort.args = db_strsplit(tmp, '\n');
	db_parsedbfile(t_tree, &sort);
	db_filltree(t_tree, &sort);
	return (0);
}


/*Looks for a rtt.db file. If found it loads the file else it will create a
 * fresh copy of the rtt.db and fill it with initial information
 * Then it will populate the t_tree with the */
t_tnode			*db_loaddatabase()
{
	t_tnode		*t_tree;
	FILE		*p_file;

	if (!(t_tree = (t_tnode *)db_memalloc(sizeof(t_tnode))))
		return (NULL);
	if (!(p_file = fopen( "rtt.db", "r")))
	{
		if (!(p_file = fopen("rtt.db", "ab")))
			return (NULL);
		fwrite("0\n0\n0\nNA", 8, 1, p_file);
		fclose(p_file);
		p_file = NULL;
	}
	if (p_file)
	{
		db_populatedb(t_tree, p_file);
		fclose(p_file);
		return (t_tree);
	}
	return(t_tree);
}

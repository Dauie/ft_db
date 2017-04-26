/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_loaddatabase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 20:07:04 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/26 14:13:35 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int			db_fillnode(t_tnode *t_tree, FILE *p_file)
{
	t_dbnfo		file;
	char		tmp[256];
	char		**value;
	
	db_initdbnfo(&file);
	if (!(fscanf(p_file, "%s", tmp)))
		return (-1);
	file.nval = atoi(tmp);
	bzero(tmp, 256);
	if (!(fscanf(p_file, "%s", tmp)))
		return (-1);
	file.ctime = atoi(tmp);
	bzero(tmp, 256);
	if (!(fscanf(p_file, "%s", tmp)))
		return (-1);
	file.agtime = atoi(tmp);
	bzero(tmp, 256);
	int i = file.nval;
	while (i-- > 0)
	{
		fscanf(p_file, "%s`", tmp);
		value = (char **)db_strsplit(tmp, ',');
		file.val = (char **)db_tbldup(&value[1], db_tbllen(&value[1]));
		/*db_tbldel(value)*/
		bzero(tmp, 256);
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


/* If the rtt.db file is found it will be read into tmp, then
 * it will be passed to "db_parsedbfile" after we will have the table file list.
 * With this list we will build the tree, filling in each node with the
 * information from a table file.*/
int				db_populatedb(t_tnode *t_tree, FILE *p_dbf)
{
	size_t		xpctdn;
	t_dbnfo		sort;
	char		tmp[256];		/*Need to define a max file size*/

	bzero(tmp, 256);
	db_initdbnfo(&sort);
	if (!(fscanf(p_dbf, "%s", tmp)))
		return (-1);
	xpctdn = atoi(tmp);
	bzero(tmp, 256);
	if (!(fscanf(p_dbf, "%s", tmp)))
		return (-1);
	sort.ctime = atoi(tmp);
	bzero(tmp, 256);
	if (!(fscanf(p_dbf, "%s", tmp)))
		return (-1);
	sort.agtime = atoi(tmp);
	bzero(tmp, 256);
	sort.nargs = sort.nval;
	while (fscanf(p_dbf, "%s", tmp))
	{
		sort.nargs++;
		db_tbladdl(sort.args, tmp, sort.nargs);
		bzero(tmp, 256);
	}
	db_filltree(t_tree, &sort);
	return (0);
}


/*Looks for a rtt.db file. If found it loads the file else it will create a
 * fresh copy of the rtt.db and fill it with initial information
 * Then it will populate the t_tree with the */
t_tnode			*db_loaddatabase()
{
	t_tnode		*t_tree;
	FILE		*p_dbf;

	if (!(t_tree = (t_tnode *)db_memalloc(sizeof(t_tnode))))
		return (NULL);
	if (!(p_dbf = fopen( "rtt.db", "r")))
	{
		if (!(p_dbf = fopen("rtt.db", "ab")))
			return (NULL);
		fwrite("0\n0\n0\nNA", 8, 1, p_dbf);
		fclose(p_dbf);
		p_dbf = NULL;
	}
	if (p_dbf)
	{
		db_populatedb(t_tree, p_dbf);
		fclose(p_dbf);
		return (t_tree);
	}
	return(t_tree);
}

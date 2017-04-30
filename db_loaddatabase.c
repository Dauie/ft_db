/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_loaddatabase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/25 20:07:04 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/29 17:55:46 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void		db_addorcreate(t_tnode **t_tree, t_dbnfo *file)
{
	t_tnode *table;

	table = NULL;
	if (*t_tree != NULL && (table = db_searchtnode(*t_tree, file)))
			db_addenoden(&table->entries, file);
	else
	{
		db_addtnoden(t_tree, file);
		if (!(table = db_searchtnode(*t_tree, file)))
			return ;
		db_addenoden(&table->entries, file);
	}
}

int			db_fillnode(t_tnode **t_tree, FILE *p_tf)
{
	t_dbnfo		file;
	char		tmp[MXNAMLEN];
	char		**value;
	
	bzero(tmp, MXNAMLEN);
	db_initdbnfo(&file);
	if (!(fscanf(p_tf, "%s", tmp)))
		return (-1);
	strcpy(file.tbl_name, tmp);
	if (!(fscanf(p_tf, "%s", tmp)))
		return (-1);
	file.nval = atoi(tmp);
	bzero(tmp, MXNAMLEN);
	if (!(fscanf(p_tf, "%s", tmp)))
		return (-1);
	file.ctime = atoi(tmp);
	bzero(tmp, MXNAMLEN);
	if (!(fscanf(p_tf, "%s", tmp)))
		return (-1);
	time(&file.mtime);
	bzero(tmp, MXNAMLEN);
	while (fscanf(p_tf, "%s", tmp) && *tmp != '\0')
	{
		if (tmp[0] == '|')
			break ;
		file.nargs++;
		value = db_strsplit(tmp, ',');
		strcpy(file.key_name, value[0]);
		file.val = db_tbldup(&value[1], db_tbllen(&value[1]));
		db_addorcreate(t_tree, &file);
		bzero(tmp, MXNAMLEN);
	}
	return (0);
}
/*Filling the tree by going through db->args (table file list)
 * and filling a node with each table file. (.tbl) */
int			db_filltree(t_tnode **t_tree, t_dbnfo *sort)
{
	int i = -1;
	FILE *p_file;
	char *dir;
	char *tmp;

	dir = NULL;
	tmp = NULL;
	while (sort->args[++i])
	{
		if (!(dir = db_strjoin("tbls/",sort->args[i])))
			return (-1);
		if (!(p_file = fopen(dir, "r")))
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
int				db_populatedb(t_tnode **t_tree, FILE *p_dbf)
{
	size_t		xpctdn;
	t_dbnfo		sort;
	char		tmp[MXNAMLEN];		/*Need to define a max file size*/

	bzero(tmp, MXNAMLEN);
	if (!(fscanf(p_dbf, "%s", tmp)))
		return (-1);
	xpctdn = atoi(tmp);
	bzero(tmp, MXNAMLEN);
	if (!(fscanf(p_dbf, "%s", tmp)))
		return (-1);
	sort.ctime = atoi(tmp);
	bzero(tmp, MXNAMLEN);
	if (!(fscanf(p_dbf, "%s", tmp)))
		return (-1);
	sort.mtime = atoi(tmp);
	bzero(tmp, MXNAMLEN);
	sort.nargs = sort.nval;
	while (fscanf(p_dbf, "%s", tmp) && *tmp != '\0')
	{
		if (tmp[0] == '|')
			break;
		sort.nargs++;
		sort.args = db_tbladdl(sort.args, tmp, sort.nargs);
		bzero(tmp, MXNAMLEN);
	}
	db_filltree(t_tree, &sort);
	return (0);
}


/*Looks for a rtt.db file. If found it loads the file else it will create a
 * fresh copy of the rtt.db and fill it with initial information
 * Then it will populate the t_tree with the */
void			db_loaddatabase(t_tnode **t_tree)
{
	FILE		*p_dbf;

	p_dbf = NULL;
	if (!(p_dbf = fopen( "rtt.db", "r")))
	{
		if (!(p_dbf = fopen("rtt.db", "ab")))
			return ;
		fwrite("0\n0\n0\nNA", 8, 1, p_dbf);
		fclose(p_dbf);
		p_dbf = NULL;
	}
	if (p_dbf)
	{
		db_populatedb(t_tree, p_dbf);
		fclose(p_dbf);
	}
}

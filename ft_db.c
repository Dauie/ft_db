/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 12:00:02 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/30 12:47:23 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

static int	db_parseflag(t_dbnfo *db)
{

		if (strcmp(db->args[0], "-ae") == 0)
			db->mode = ADD_NTRY;
		else if (strcmp(db->args[0], "-ee") == 0)
			db->mode = EDIT_NTRY;
		else if (strcmp(db->args[0], "-dt") == 0)
			db->mode = DEL_TBL;
		else if (strcmp(db->args[0], "-de") == 0)
			db->mode = DEL_NTRY;
		else if (strcmp(db->args[0], "-pt") == 0)
			db->mode = PRNT_TBL;
		else if (strcmp(db->args[0], "-ptm") == 0)
			db->mode = PRNT_TBLM;
		else if (strcmp(db->args[0], "-pe") == 0)
			db->mode = PRNT_NTRY;
		else if (strcmp(db->args[0], "-pd") == 0)
			db->mode = PRNT_DB;
		else if (strcmp(db->args[0], "-xt") == 0)
			db->mode = XPRT_TBL;
		else if (strcmp(db->args[0], "-xe") == 0)
			db->mode = XPRT_NTRY;
		if (db->mode > 0)
		{	
			db->tbln_act = true;
			return (1);
		}
		else
			return (0);
}

static int		db_verifyinput(t_dbnfo *db)
{
	if (db->tbl_name[0] == '\0' && db->mode > 1)
		printf("ft_db: table name is required\nusage: ft_db [-ae -ee -dt -de ...] [table] [key] [value] [new value]\n --help for more\n");
	else if (db->key_name[0] == '\0' && db->mode > 6)
		printf("ft_db: key name is required\nusage: ft_db [-ae -ee -dt -de ...] [table] [key] [value] [new value]\n --help for more\n");
	else if (!db->val && db->mode != DEL_TBL && db->mode > 6)
		printf("ft_db: value is required for key\nusage: ft_db [-ae -ee -dt -de ...] [table] [key] [value] [new value]\n --help for more\n");
	return(-1);
}

int		db_parseargs(t_dbnfo *db, int len)
{
	int i = 0;
	time(&db->mtime);
	if (strcmp(db->args[0], "--help") == 0)
	{
		db_printhelp();
		return (0);
	}
	if (!(i = db_parseflag(db)))
	{
		printf("ft_db: illegal option -- %s\nusage: ft_db [-ae -et -ee -dt -de] [table] [key] [value] [new value]\n", db->args[i]);
		return (-1);
	}
	while (i < len)
	{ 
		if (db->tbln_act == true && db->mode > 0)
		{
			strcpy(db->tbl_name, db->args[i]);
			db->tbln_act = false;
			db->key_act = true;
		}
		else if (db->key_act == true && db->mode > 0)
		{
			strcpy(db->key_name, db->args[i]);
			db->key_act = false;
			db->val_act = true;
		}
		else if (db->val_act == true && db->mode > 0)
		{
			db->nval = len - i;
			if (!(db->val = db_tbldup(&db->args[i], len - i)))
				return (-1);
			db->val_act = false;
			break;
		}
		i++;
	}
	return (db_verifyinput(db));
}

int		db_modemaster(t_tnode **t_tree, t_dbnfo *db)
{
	if (!db)
		return (-1);
	if (db->mode == NRML)
		return (0);
	else if (db->mode == ADD_NTRY)
		db_addorcreate(t_tree, db);
	else if (db->mode == PRNT_DB)
		db_printdb(*t_tree);
	else if (db->mode == PRNT_TBL)
		db_printtable(*t_tree, db);
/*	else if (db->mode == EDIT_NTRY)
		db_editenoder();
	else if (db->mode == DEL_NTRY)
		db_clearetree(tree);
	else if (db->mode == DEL_TBL)
		ls_cleartree(tree);*/
	else
		return(-1);
	return (0);
}

int			main(int ac, char **av)
{
	t_dbnfo		db;
	t_tnode		*t_tree;
	
	t_tree = NULL;
	if (ac > 1)
	{
		db_initdbnfo(&db);
		if (!(db.args = db_tbldup(&av[1], ac - 1)))
			return (-1);
		if (!(db_parseargs(&db, ac - 1)))
			return (-1);
		db_loaddatabase(&t_tree);
		if (t_tree == NULL)
			return (-1);
		db_modemaster(&t_tree, &db);
		db_savedb(&t_tree, &db);
		/*
		*  2.If there is DB already. Load it.
		*   3. Carry out operation given by user.
		*/
		return (1);
	}
	else
		printf("usage: ft_db [-ae -ee -dt -de ...] [table] [key] [value] [new value]\n");
	return (0);
}

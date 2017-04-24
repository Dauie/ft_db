/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 12:00:02 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/22 18:14:36 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

static int	db_parseflag(t_dbnfo *db)
{
		if (strcmp(db->args[0], "-at") == 0)
			db->mode = ADD_TBL;
		else if (strcmp(db->args[0], "-ae") == 0)
			db->mode = ADD_NTRY;
		else if (strcmp(db->args[0], "-et") == 0)
			db->mode = EDIT_TBL;
		else if (strcmp(db->args[0], "-ee") == 0)
			db->mode = EDIT_RNTRY;
		else if (strcmp(db->args[0], "-dt") == 0)
			db->mode = DEL_TBL;
		else if (strcmp(db->args[0], "-de") == 0)
			db->mode = DEL_NTRY;
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
	if (db->tbl_nam && db->key_nam && db->val)
		return (0);
	else if (!db->tbl_nam)
		printf("ft_db: table name is required\nusage: ft_db [-at -ae -et -ee -dt -de] [table] [key] [value] [new value]\n");
	else if (!db->key_nam)
		printf("ft_db: key name is required\nusage: ft_db [-at -ae -et -ee -dt -de] [table] [key] [value] [new value]\n");
	else if (!db->val && db->mode != DEL_TBL)
		printf("ft_db: value is required for key\nusage: ft_db [-at -ae -et -ee -dt -de] [table] [key] [value] [new value]\n");
	return(-1);
}

int		db_parseargs(t_dbnfo *db, int len)
{
	int i = 0;
	time(&db->agtime);
	if (!(i = db_parseflag(db)))
		printf("ft_db: illegal option -- %s\nusage: ft_db [-at -ae -et -ee -dt -de] [table] [key] [value] [new value]\n", db->args[i]);
	while (i < len)
	{ 
		if (db->tbln_act == true && db->mode > 0)
		{
			if (!(db->tbl_nam = strdup(db->args[i])))
				return (-1);
			db->tbln_act = false;
			db->key_act = true;
		}
		else if (db->key_act == true && db->mode > 0)
		{
			if (!(db->key_nam = strdup(db->args[i])))
				return (-1);
			db->key_act = false;
			db->val_act = true;
		}
		else if (db->val_act == true && db->mode > 0)
		{
			if (!(db->val = db_tbldup(&db->args[i], len - i)))
				return (-1);
			db->val_act = false;
			break;
		}
		i++;
	}
	return (db_verifyinput(db));
}

void		db_modemaster(t_dbnode *tree, t_dbnfo db)
{
	if (!db)
		return ;
	if (db.mode == NRML)
		return ;
	else if (db.mode == ADD_TBL)
		ls_addtnodet(tree, tree->tbl_name);
	else if (db.mode == ADD_NTRY)
		ls_addtnoden(tree, tree->entries->ename);
	else if (db.mode == EDIT_RNTRY)
		ls_editenoder();
	else if (db.mode == EDIT_APNTRY)
		ls_editenodea();
	else if (db.mode == EDIT_TBL)
		ls_edittnodet();
	else if (db.mode == DEL_NTRY)
		ls_clearetree(tree);
	else if (db.mode == DEL_TBL)
		ls_cleartree(tree);
}

int			main(int ac, char **av)
{
	t_dbnfo		db;
	t_dbnode	*tree;
	
	tree = NULL;
	if (ac > 1)
	{
		db_initdbnfo(&db);
		db.args = db_tbldup(&av[1], ac - 1);
		db_parseargs(&db, ac - 1);
		if (db.tbl_nam)
			printf("tbln: %s\n",db.tbl_nam);
		if (db.key_nam)
			printf("keynam: %s\n",db.key_nam);
		if (db.val)
		{
			int i = -1;
			while (db.val[++i])
				printf("val: %s\n", db.val[i]);
		}
		if (!(tree = db_loaddatabase(db)))
			return (-1);
		db_modemaster(tree, db);
		/*
		*  2.If there is DB already. Load it.
		*   3. Carry out operation given by user.
		*/
		return (1);
	}
	else
		printf("usage: ft_db [-at -ae -et -ee -dt -de] [table] [key] [value] [new value]\n");
	return (0);
}

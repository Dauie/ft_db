/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 12:00:02 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/21 19:51:18 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		db_parseargs(t_dbnfo *db, int len)
{
	int i = -1;

	while (++i < len)
	{
		if (db->mode > 0 && db->tbln_act == false && db->key_act == false 
				&& db->val_act == false && db->nval_act == false)
			db->tbln_act = true;
		if (db->tbln_act == true && db->mode > 0)
		{
			db->a_tblnam = strdup(db->args[i]);
			db->tbln_act = false;
			db->key_act = true;
		}
		else if (db->key_act == true && db->mode > 0)
		{
			db->a_keynam = strdup(db->args[i]);
			db->key_act = false;
			db->val_act = true;
		}
		else if (db->val_act == true && db->mode > 0)
		{
			*db->a_val = strdup(db->args[i]);
			db->val_act = false;
			if (db->mode == EDIT_RNTRY || db->mode == EDIT_APNTRY)
				db->nval_act = true;
		}
		else if (db->nval_act == true)
		{

		}
		else if (strcmp(db->args[i], "-at") == 0)
			db->mode = ADD_TBL;
		else if (strcmp(db->args[i], "-ae") == 0)
			db->mode = ADD_NTRY;
		else if (strcmp(db->args[i], "-et") == 0)
			db->mode = EDIT_TBL;
		else if (strcmp(db->args[i], "-ee") == 0)
			db->mode = EDIT_RNTRY;
		else if (strcmp(db->args[i], "-dt") == 0)
			db->mode = DEL_TBL;
		else if (strcmp(db->args[i], "-de") == 0)
			db->mode = DEL_NTRY;
		else
			printf("Usage:\"./ft_db [-at, -ae, -et, -ee, -dt, -de] [table] [entry] [value] [nvalue]\"\n--help for more\n");

	}
	return (1);
}

int			main(int ac, char **av)
{
	t_dbnfo		db;
	t_dbnode	*tree;

	if (ac > 1)
	{
		db_initdbnfo(&db);
		db.args = db_tbldup(&av[1], ac - 1);
		db_parseargs(&db, ac - 1);
		tree = db_loaddata(&db);
		printf("name: %s, value: %s\n", db.a_tblnam, *db.a_val);
		
		/*
		*  2.If there is DB already. Load it.
		*   3. Carry out operation given by user.
		*/
		return (1);
	}
	return (0);
}

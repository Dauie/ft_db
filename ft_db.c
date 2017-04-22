/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 12:00:02 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/22 12:06:54 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		db_parseargs(t_dbnfo *db, int len)
{
	int i = -1;

	while (++i < len--)
	{
		if (db->args[i][0] == '-')
		{
			if (strcmp(db->args[i], "-at") == 0)
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
				printf("ft_db: illegal option -- %s\nusage: ft_db [-at -ae -et -ee -dt -de] [table] [key] [value] [new value]",db->args[i]);
			continue ;
		}
		else if (db->mode > 0 && db->tbln_act == false && db->key_act == false 
				&& db->val_act == false && db->nval_act == false)
			db->tbln_act = true;
		else if (db->tbln_act == true && db->mode > 0)
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
			if (db->mode != EDIT_RNTRY && db->mode != EDIT_APNTRY)
				db->a_val = db_tbldup(&db->args[i], len);
			else
				*db->a_val = strdup(db->args[i]);
			db->val_act = false;
			if (db->mode == EDIT_RNTRY || db->mode == EDIT_APNTRY)
				db->nval_act = true;
		}
		else if (db->nval_act == true)
			db->a_nval = db_tbldup(&db->args[i], len);
	}
	return (1);
}

int			main(int ac, char **av)
{
	t_dbnfo		db;
	/*t_dbnode	*tree;*/

	if (ac > 1)
	{
		db_initdbnfo(&db);
		db.args = db_tbldup(&av[1], ac - 1);
		db_parseargs(&db, ac - 1);
		if (db.a_tblnam)
			printf("%s",db.a_tblnam);
		if (db.a_keynam)
			printf("%s",db.a_keynam);
		/*
		*  2.If there is DB already. Load it.
		*   3. Carry out operation given by user.
		*/
		return (1);
	}
	printf("usage: ft_db [-at -ae -et -ee -dt -de] [table] [key] [value] [new value]");

	return (0);
}

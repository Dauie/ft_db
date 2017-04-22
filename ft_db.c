/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 12:00:02 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/22 12:33:42 by rlutt            ###   ########.fr       */
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

int		db_parseargs(t_dbnfo *db, int len)
{
	int i = 0;
	
	if (!(i = db_parseflag(db)))
		printf("ft_db: illegal option -- %s\nusage: ft_db [-at -ae -et -ee -dt -de] [table] [key] [value] [new value]", db->args[i]);
	while (++i < len--)
	{ 
		if (db->mode > 0 && db->tbln_act == false && db->key_act == false 
				&& db->val_act == false && db->nval_act == false)
			db->tbln_act = true;
		else if (db->tbln_act == true && db->mode > 0)
		{
			db->tblnam = strdup(db->args[i]);
			db->tbln_act = false;
			db->key_act = true;
		}
		else if (db->key_act == true && db->mode > 0)
		{
			db->keynam = strdup(db->args[i]);
			db->key_act = false;
			db->val_act = true;
		}
		else if (db->val_act == true && db->mode > 0)
		{
			if (db->mode != EDIT_RNTRY && db->mode != EDIT_APNTRY)
				db->val = db_tbldup(&db->args[i], len);
			else
				*db->val = strdup(db->args[i]);
			db->val_act = false;
			if (db->mode == EDIT_RNTRY || db->mode == EDIT_APNTRY)
				db->nval_act = true;
		}
		else if (db->nval_act == true)
			db->nval = db_tbldup(&db->args[i], len);
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
		if (db.tblnam)
			printf("%s",db.tblnam);
		if (db.keynam)
			printf("%s",db.keynam);
		/*
		*  2.If there is DB already. Load it.
		*   3. Carry out operation given by user.
		*/
		return (1);
	}
	printf("usage: ft_db [-at -ae -et -ee -dt -de] [table] [key] [value] [new value]");

	return (0);
}

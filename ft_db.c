/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 12:00:02 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/21 16:22:33 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int		db_parseargs(t_dbnfo *db, int len)
{
	int i = -1;

	while (++i < len)
	{
		if (db->n_actn == true && db->action > 0)
		{
			db->a_nam = strdup(db->args[i]);
			db->n_actn = false;
			db->v_actn = true;
		}
		else if (db->v_actn == true && db->action > 0)
		{
			db->a_val = strdup(db->args[i]);
			db->action = false;
		}
		else if (strcmp(db->args[i], "-at") == 0)
			db->action = ADD_TBL;
		else if (strcmp(db->args[i], "-ae") == 0)
			db->action = ADD_NTRY;
		else if (strcmp(db->args[i], "-et") == 0)
			db->action = EDIT_TBL;
		else if (strcmp(db->args[i], "-ee") == 0)
			db->action = EDIT_NTRY;
		else if (strcmp(db->args[i], "-dt") == 0)
			db->action = DEL_TBL;
		else if (strcmp(db->args[i], "-de") == 0)
			db->action = DEL_NTRY;
		else
			printf("Usage:\n \"./ft_db [-at, -ae, -et, -ee, -dt, -de] [name] [value]\"\n--help for more\n");
		if (db->action > 0 && db->n_actn == false && db->v_actn == false)
			db->n_actn = true;
	}
	return (1);
}

int			main(int ac, char **av)
{
	t_dbnfo		db;

	if (ac > 1)
	{
		db_initdbnfo(&db);
		db.args = db_tbldup(&av[1], ac - 1);
		db_parseargs(&db, ac - 1);
		printf("name: %s, value: %s\n", db.a_nam, db.a_val);
		/*1.Get arguments from user.
		*  2.If there is DB already. Load it.
		*   3. Carry out operation given by user.
		*/
		return (1);
	}
	return (0);
}

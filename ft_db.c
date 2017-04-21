/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 12:00:02 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/21 15:05:17 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void		db_parseargs(t_dbnfo *db)
{
	
}

int			main(int ac, char **av)
{
	t_dbnfo		db;

	if (ac > 1)
	{
		db_initdbnfo(&db);
		db.args = db_tbldup(&av[1], ac - 1);
		db_parseargs(&db);
		/*1.Get arguments from user.
		*  2.If there is DB already. Load it.
		*   3. Carry out operation given by user.
		*/
		return (1);
	}
	return (0);
}

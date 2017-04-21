/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/21 12:00:02 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/21 12:41:17 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int			main(int ac, char **av)
{
	t_dbnfo		db;

	if (ac > 1)
	{
		db_inidbnfo(&db);
		/*1.Get arguments from user.
		*  2.If there is DB already. Load it.
		*   3. Carry out operation given by user.
		*/
		return (1);
	}
	return (0);
}

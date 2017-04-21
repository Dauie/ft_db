/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_tbldup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/11 15:26:49 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/21 15:02:50 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

char		**db_tbldup(char **tbl, int len)
{
	int		i;
	char	**res;
	char	**tmp;

	i = -1;
	res = (char **)malloc(sizeof(char *) * (len + 1));
	tmp = res;
	while (++i < len)
	{
		*tmp = strdup(*tbl);
		tbl++;
		tmp++;
	}
	return (res);
}

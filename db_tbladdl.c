/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_tbladdl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/04 11:42:58 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/26 14:23:28 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

char		**db_tbladdl(char **tbl, char *line, size_t nmembrs)
{
	size_t		i;
	char	**res;
	char	**tmp;

	i = -1;
	tmp = NULL;
	if (nmembrs > 1)
	{
		if (!(res = (char **)realloc(tbl, sizeof(char *) * (nmembrs + 2))))
			return (NULL);
		tmp = res;
		while (++i < nmembrs)
		{
			*tmp = strdup(*tbl);
			tbl++;
			tmp++;
		}
		*tmp = strdup(line);
	}
	else
	{
		if (!(res = (char **)realloc(tbl, sizeof(char *) + 1)))
			return (NULL);
		*res = strdup(line);
	}
		return (res);
}

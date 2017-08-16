/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:48:19 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/25 13:35:45 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

static size_t		db_cntwrds(char *str, char c)
{
	size_t	i;
	char	*sc;

	i = 0;
	sc = str;
	if (str[i] != c)
		i++;
	while (*sc)
	{
		if ((*(sc - 1) == c || *(sc - 1) == 0) && *sc != c)
			i++;
		sc++;
	}
	return (i);
}

static size_t		db_nxtwrdlen(char *str, char c)
{
	size_t i;

	i = 0;
	while (*str != c && *str)
	{
		i++;
		str++;
	}
	return (i);
}

static char		*db_xtrctnxtwrd(char *str, char c, size_t *i)
{
	size_t		y;
	char		*res;
	size_t		len;

	y = 0;
	len = db_nxtwrdlen(&str[*i], c);
	if (!(res = (char *)db_memalloc(sizeof(char) * len + 1)))
		return (NULL);
	if (str != NULL)
	{
		while (str[*i] != c && str[*i])
		{
			res[y] = str[*i];
			y++;
			*i += 1;
		}
	}
	res[y] = '\0';
	return (res);
}

char			**db_strsplit(char const *s, char c)
{
	char		**res;
	size_t		i;
	size_t		ii;
	size_t		wcnt;

	i = 0;
	ii = 0;
	if (!s || !c)
		return (NULL);
	wcnt = db_cntwrds((char*)s, c);
	if (!(res = (char **)db_memalloc(sizeof(char *) * (wcnt + 1))))
		return (NULL);
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && ii < wcnt)
	{
		res[ii] = db_xtrctnxtwrd((char *)s, c, &i);
		ii++;
		while (s[i] && s[i] == c)
			i++;
	}
	res[ii] = NULL;
	return (res);
}

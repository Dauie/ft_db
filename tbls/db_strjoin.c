/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 14:15:42 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/29 14:19:14 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

char		*db_strnew(size_t size)
{
	char	*res;

	res = (char *)db_memalloc(sizeof(char) * (size + 1));
	if (!res)
		return (NULL);
	return (res);
}

char		*db_strjoin(char const *s1, char const *s2)
{
	char	*ns;
	int		i;
	int		it;

	i = 0;
	it = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(ns = db_strnew(strlen(s1) + strlen(s2))))
		return (NULL);
	if (s1 != NULL && s2 != NULL)
	{
		while (s1[i])
		{
			ns[i] = s1[i];
			i++;
		}
		while (s2[it])
			ns[i++] = s2[it++];
	}
	ns[i] = '\0';
	return (ns);
}

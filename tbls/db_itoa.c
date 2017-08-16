/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 14:23:04 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/29 14:23:07 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

size_t		db_numlen(intmax_t nb, int bse)
{
	size_t		i;

	i = 1;
	if (nb < 0)
		i++;
	while (nb /= bse)
		i++;
	return (i);
}

char		*db_itoa(intmax_t nbg)
{
	intmax_t	nb;
	size_t		sz;
	char		*res;

	nb = nbg;
	sz = db_numlen((long long)nbg, 10);
	if (!(res = ((char *)db_memalloc(sz + 1))))
		return (NULL);
	sz--;
	if (nbg == 0)
		return (strdup("0"));
	if (nbg < 0)
		nb = nb * -1;
	while (nb != 0)
	{
		res[sz] = nb % 10 + '0';
		nb = nb / 10;
		sz--;
	}
	if (nbg < 0)
		res[0] = '-';
	return (res);
}


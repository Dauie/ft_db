/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 19:54:05 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/19 19:57:20 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_DB_H
#define FT_DB_H


typedef struct s_dbnfo
{
	int		inx;
}

typedef struct	t_ndata
{
	void		***tblpt;
}

typedef struct s_dbnode
{
	char		*name;
	s_dbnode	*left;
	sdbnode		*right;
}			t_dbnode;



#endif

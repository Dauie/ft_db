/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 19:54:05 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/19 20:06:44 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_DB_H
#define FT_DB_H


typedef struct	s_dbnfo
{
	int		inx;
}				t_dbnfo;

typedef struct	s_ndata
{
	void		***tblpt;
}				t_ndata;

typedef struct s_dbnode
{
	char		*name;
	s_dbnode	*left;
	s_dbnode		*right;
}			t_dbnode;



#endif

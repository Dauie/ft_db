/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 19:54:05 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/19 21:04:19 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_DB_H
#define FT_DB_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct	s_dbnfo
{
	int			inx;
}				t_dbnfo;

typedef struct	s_ndata
{
	long		tbl_ctime;
	long		**tbl_mtime;
	void		**tbl;
	s_ndata		*next;
}				t_ndata;

typedef struct s_dbnode
{
	char		*name;
	char		type;
	t_ndata		*members;
	s_dbnode	*left;
	s_dbnode	*right;
}				t_dbnode;

typedef struct s_tridbnode
{
	t_dbnode	*elem;
	t_dbnode	*ntmp;
	t_dbnode	*ttmp;
}				t_tridbnode;

#endif

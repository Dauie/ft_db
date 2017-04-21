/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 19:54:05 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/21 12:28:46 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_DB_H
#define FT_DB_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct	s_dbnfo
{
	bool	addtbl_f;
	bool	deltbl_f;
	bool	addntry_f;
	bool	delntry_f;
	bool	editntry_f;
	
}				t_dbnfo;

typedef struct	s_ndata
{
	long		tbl_ctime;
	long		**tbl_mtime;
	char		**bse_tbl;
	intmax_t	**num_tbl;
}				t_ndata;

typedef struct s_dbnode
{
	int			wght;
	char		*tbl_name;
	s_dbnode	*left;
	s_dbnode	*right;
	t_ndata		data;
}				t_dbnode;

typedef struct s_tridbnode
{
	t_dbnode	*elem;
	t_dbnode	*ntmp;
	t_dbnode	*ttmp;
}				t_tridbnode;

void	db_initdbnfo(t_dbnfo *db);
void	db_initnode(t_dbnode *elem);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 19:54:05 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/21 16:13:37 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_DB_H
#define FT_DB_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef	enum	s_mode
{
	NRML,
	ADD_TBL,
	ADD_NTRY,
	EDIT_NTRY,
	EDIT_TBL,
	DEL_NTRY,
	DEL_TBL
}				t_mode;

typedef struct	s_dbnfo
{
	char	**args;
	char	*a_nam;
	char	*a_val;
	bool	n_actn;
	bool	v_actn;
	t_mode	action;
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
	int				wght;
	char			*tbl_name;
	struct s_dbnode	*left;
	struct s_dbnode	*right;
	t_ndata			data;
}					t_dbnode;

typedef struct s_tridbnode
{
	t_dbnode	*elem;
	t_dbnode	*ntmp;
	t_dbnode	*ttmp;
}				t_tridbnode;

void	db_initdbnfo(t_dbnfo *db);
void	db_initnode(t_dbnode *elem);
void 	ls_addtnoden(t_dbnode **tree, char *name, char type);
void 	ls_addtnodet(t_dbnode **tree, char *name, char type);
void	ls_cleartree(t_dbnode **tree);
void	db_initdbnfo(t_dbnfo *db);
void 	ls_printtree(t_dbnode *tree);
void 	ls_revprinttree(t_dbnode *tree);
char	**db_tbldup(char **tbl, int len);
int		ls_treesearch(t_dbnode *tree, char *name);
#endif

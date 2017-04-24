/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 19:54:05 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/24 14:04:14 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_DB_H
#define FT_DB_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

#define MXNAMLEN 42

typedef	enum	s_mode
{
	NRML,
	ADD_TBL,
	ADD_NTRY,
	EDIT_RNTRY,
	EDIT_APNTRY,
	EDIT_TBL,
	DEL_NTRY,
	DEL_TBL
}				t_mode;

typedef struct	s_dbnfo
{
	char		**args;
	time_t		agtime;
	char		*tbl_nam;
	char		*key_nam;
	char		**val;
	char		**nval;
	bool		tbln_act;
	bool		key_act;
	bool		val_act;
	bool		nval_act;
	t_mode		mode;
}				t_dbnfo;

typedef struct	s_entrynode
{
	char				ename[MXNAMLEN];
	time_t				emodtime;
	time_t				ecretime;
	char				**cmembr;
	intmax_t			**nmembr;
	struct s_entrynode	*left;
	struct s_entrynode	*right;
}						t_enode;

typedef struct s_dbnode
{
	size_t		tblamt;
	char			tbl_name[MXNAMLEN];
	time_t			tbl_ctime;
	time_t			tbl_mtime;
	t_enode			*entries;
	char			lmmbr[MXNAMLEN];
	struct s_dbnode	*left;
	struct s_dbnode	*right;
}					t_dbnode;

typedef struct s_tridbnode
{
	t_dbnode	*elem;
	t_dbnode	*ntmp;
	t_dbnode	*ttmp;
}				t_tridbnode;

void	db_initdbnfo(t_dbnfo *db);
void	db_initdbnode(t_dbnode *elem);
void 	ls_addtnoden(t_dbnode **tree, char *name);
void 	ls_addtnodet(t_dbnode **tree, char *name);
void	ls_cleartree(t_dbnode **tree);
void	db_initdbnfo(t_dbnfo *db);
void 	ls_printtree(t_dbnode *tree);
void 	ls_revprinttree(t_dbnode *tree);
char	**db_tbldup(char **tbl, int len);
int		ls_treesearch(t_dbnode *tree, char *name);
t_dbnode *db_loaddata(t_dbnfo *db);

#endif

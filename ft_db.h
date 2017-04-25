/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 19:54:05 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/25 14:29:00 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_DB_H
#define FT_DB_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <ctype.h>

#define MXNAMLEN 128

typedef	enum			s_mode
{
	NRML,
	ADD_TBL,
	ADD_NTRY,
	EDIT_RNTRY,
	EDIT_APNTRY,
	EDIT_TBL,
	DEL_NTRY,
	DEL_TBL
}						t_mode;

typedef struct			s_dbnfo
{
	char				**args;
	time_t				agtime;
	char				*tbl_name;
	char				*key_nam;
	char				**val;
	size_t				nval;
	bool				tbln_act;
	bool				key_act;
	bool				val_act;
	bool				nval_act;
	t_mode				mode;
}						t_dbnfo;

typedef struct			s_entrynode
{
	char				ename[MXNAMLEN];
	time_t				emodtime;
	time_t				ecretime;
	char				**cmembr;
	intmax_t			**nmembr;
	struct s_entrynode	*left;
	struct s_entrynode	*right;
}						t_enode;

typedef struct			s_dbnode
{
	size_t				tblamt;
	char				tbl_name[MXNAMLEN];
	t_enode				*entries;
	char				lmmbr[MXNAMLEN];
	struct s_dbnode		*left;
	struct s_dbnode		*right;
}						t_dbnode;

typedef struct			s_tridbnode
{
	t_dbnode			*elem;
	t_dbnode			*ntmp;
	t_dbnode			*ttmp;
}						t_tridbnode;

void					db_addtnoden(t_dbnode **t_tree, t_dbnfo *db);
void					db_addtnodet(t_dbnode **tree, t_dbnfo *db);
void					db_cleartree(t_dbnode **tree);
void					db_clearetree(t_dbnode **tree);
void					db_initdbnfo(t_dbnfo *db);
void					db_initdbnode(t_dbnode *elem);
void					db_initenode(t_enode *entry);
void					db_populatedb(t_dbnode *t_tree, t_dbnfo *db, FILE *p_file);
t_dbnode				*db_loaddatabase(t_dbnfo *db);
void					*db_memalloc(size_t size);
void					db_printdbmeta(t_dbnode *t_tree);
void					db_printdb(t_dbnode **t_tree);
void					db_printtblmeta(t_dbnode *t_tree);
void					db_printtbl(char *tbl_name, t_enode **e_tree);
void					db_printentrymeta(t_enode *entry);
void					db_printentry(t_enode *entry);
void					db_printttree(t_dbnode *t_tree);
void					db_printttreeval(t_dbnode *t_tree);
void					db_revprintttree(t_dbnode *t_tree);
void					db_printetree(t_enode *e_tree);
void					db_revprintetree(t_enode *e_tree);
char					**db_tbldup(char **tbl, int len);
void					db_tbldel(char **tbl);
int						db_search_tnam(t_dbnode *tree, char *name);
char					**db_strsplit(char const *s, char c);
#endif

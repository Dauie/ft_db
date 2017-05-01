/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_db.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/19 19:54:05 by rlutt             #+#    #+#             */
/*   Updated: 2017/05/01 14:37:45 by rlutt            ###   ########.fr       */
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

static char G_TSYM[] = "\u0950";
static char G_ESYM[] = "\u06de";
static char G_EDIV[] = "\u0700";
#define MXNAMLEN 24

typedef	enum			s_mode
{
	NRML,
	PRNT_DB,
	DEL_TBL,
	PRNT_TBL,
	PRNT_TBLM,
	PRNT_NTRY,
	XPRT_TBL,
	ADD_NTRY,
	DEL_VAL,
	DEL_NTRY,
	PRNT_NTRYM,
	XPRT_NTRY
}						t_mode;

typedef struct			s_dbnfo
{
	char				**args;
	size_t				nargs;
	time_t				mtime;
	time_t				ctime;
	time_t				atime;
	char				tbl_name[MXNAMLEN];
	char				key_name[MXNAMLEN];
	char				**val;
	size_t				nval;
	bool				tbln_act;
	bool				key_act;
	bool				val_act;
	bool				nval_act;
	t_mode				mode;
}						t_dbnfo;

typedef struct			s_enode
{
	char				ename[MXNAMLEN];
	time_t				ctime;
	time_t				mtime;
	char				**cmembr;
	intmax_t			**nmembr;
	struct s_enode		*left;
	struct s_enode*		right;
}						t_enode;

typedef struct			s_tnode
{
	char				tbl_name[MXNAMLEN];
	size_t				tblamt;
	time_t				ctime;
	time_t				mtime;
	t_enode				*entries;
	struct s_tnode		*left;
	struct s_tnode		*right;
}						t_tnode;

typedef struct			s_tridbnode
{
	t_tnode				*elem;
	t_tnode				*ntmp;
	t_tnode				*ttmp;
}						t_tridbnode;

typedef struct			s_trienode
{
	t_enode				*elem;
	t_enode				*ntmp;
	t_enode				*ttmp;
}						t_trienode;

char					*db_itoa(intmax_t nbg);
void					db_addtnoden(t_tnode **t_tree, t_dbnfo *db);
void					db_addenoden(t_enode **t_tree, t_dbnfo *db);
void					db_cleartree(t_tnode **tree);
void					db_clearetree(t_tnode **tree);
void					db_initdbnfo(t_dbnfo *db);
void					db_inittnode(t_tnode *elem);
void					db_initenode(t_enode *entry);
int						db_populatedb(t_tnode **t_tree, FILE *p_dbf);
void					db_loaddatabase(t_tnode **t_tree);
int						db_savedb(t_tnode **t_tree, t_dbnfo *info);
void					*db_memalloc(size_t size);
void					db_printhelp(void);
void					db_printdbmeta(t_tnode *t_tree);
void					db_printdb(t_tnode *t_tree);
void					db_printtable(t_tnode *t_tree, t_dbnfo *info);
void					db_printtblmeta(t_tnode *t_tree, t_dbnfo *info);
void					db_printentrymeta(t_enode *entry);
void					db_printentry(t_tnode *t_tree, t_dbnfo *info);
void					db_printttree(t_tnode *t_tree);
void					db_printttreeval(t_tnode *t_tree);
void					db_revprintttree(t_tnode *t_tree);
void					db_printetree(t_enode *e_tree);
void					db_revprintetree(t_enode *e_tree);
char					**db_tbldup(char **tbl, int len);
char					**db_tblrmline(char **tbl, char *rm, int len);
void					db_tbldel(char **tbl);
char					**db_tbladdl(char **tbl, char *line, size_t nmembrs);
char					**db_strsplit(char const *s, char c);
char					*db_strjoin(char const *s1, char const *s2);
size_t					db_tbllen(char **tbl);
void					db_delvalue(t_tnode *t_tree, t_dbnfo *info);
void					db_ttreelen(t_tnode *t_tree, size_t  *len);
void					db_etreelen(t_enode *e_tree, size_t  *len);
t_enode					*db_searchenode(t_enode *e_tree, t_dbnfo *info);
t_tnode					*db_searchtnode(t_tnode *t_tree, t_dbnfo *info);
void					db_addorcreate(t_tnode **t_tree, t_dbnfo *file);
#endif

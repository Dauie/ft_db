/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_savetree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 14:23:10 by rlutt             #+#    #+#             */
/*   Updated: 2017/05/04 12:47:48 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

int			db_numtofile(intmax_t num, FILE *p_dbf)
{
	char	*chld;
	
	if (!(chld = db_itoa(num)))
		return (-1);
	fputs(chld, p_dbf);
	fputs("\n", p_dbf);
	return (0);
}

void		db_entriestofile(t_enode *e_tree, FILE *p_tf, t_dbnfo *info)
{
	size_t i;

	i = -1;
	if (info->mode == DEL_NTRY)
		if (strcmp(info->key_name, e_tree->ename) == 0)

	if (!e_tree)
		return ;
	if (e_tree->left)
		db_entriestofile(e_tree->left, p_tf, info);
	if (info->mode == DEL_NTRY && strcmp(info->key_name, e_tree->ename) == 0)
		;
	else
	{
		fputs(e_tree->ename, p_tf);
		fputs("|",p_tf);
		while (e_tree->cmembr[++i])
		{
			fputs(e_tree->cmembr[i], p_tf);
			fputs("|", p_tf);
		}
		fputs("\n", p_tf);
	}
	if (e_tree->right)
		db_entriestofile(e_tree->right, p_tf, info);
}

void		db_saveentrylist(t_tnode *t_tree, t_dbnfo *info)
{
	char	*filename;
	size_t	len;
	FILE	*p_tf;
	
	if (!(filename = db_strjoin(t_tree->tbl_name, ".tbl")))
		return ;
	if (!(filename = db_strjoin("tbls/", filename)))
		return ;
	if (!(p_tf = fopen(filename, "wb+")))
	{
		printf("%s: %s is corrupt or missing",G_TSYM, filename);
		return ;
	}
	db_etreelen(t_tree->entries, &len);
	fputs(t_tree->tbl_name,p_tf);
	fputs("\n", p_tf);
	db_numtofile(len, p_tf);
	db_numtofile(t_tree->ctime, p_tf);
	db_numtofile(t_tree->mtime, p_tf);
	db_entriestofile(t_tree->entries, p_tf, info);
	fputs("|\n", p_tf);
	fclose(p_tf);
}

void		db_savetbllist(t_tnode *t_tree, FILE *p_dbf, t_dbnfo *info)
{
	if (!t_tree)
		return ;
	if (t_tree->left)
		db_savetbllist(t_tree->left, p_dbf, info);
	fputs(t_tree->tbl_name, p_dbf);
	fputs(".tbl\n",p_dbf);
	db_saveentrylist(t_tree, info);
	if (t_tree->right)
		db_savetbllist(t_tree->right, p_dbf, info);
}


int			db_savedb(t_tnode **t_tree, t_dbnfo *info)
{
	FILE	*p_dbf;
	size_t	len;

	len = 0;
	if (!(p_dbf = fopen("rtt.db", "wb+")))
	{
		printf("%s error %s trouble saving db", G_TSYM, G_EDIV);
		return (-1);
	}
	db_ttreelen(*t_tree, &len);
	db_numtofile(len, p_dbf);
	db_numtofile(info->ctime, p_dbf);
	db_numtofile(info->mtime, p_dbf);
	db_savetbllist(*t_tree, p_dbf, info);

	fclose(p_dbf);
	return (0);
}


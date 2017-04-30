/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_ttreelen.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/29 12:31:53 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/29 17:39:42 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void		db_ttreelen(t_tnode *t_tree, size_t  *len)
{
	if (!t_tree)
		return ;
	if (t_tree->left)
		db_ttreelen(t_tree->left, len);
	*len += 1;
	if (t_tree->right)
		db_ttreelen(t_tree->right, len);
}

void		db_etreelen(t_enode *e_tree, size_t  *len)
{
	if (!e_tree)
		return ;
	if (e_tree->left)
		db_etreelen(e_tree->left, len);
	*len += 1;
	if (e_tree->right)
		db_etreelen(e_tree->right, len);
}

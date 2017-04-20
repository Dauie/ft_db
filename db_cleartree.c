/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_cleartree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:07:26 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/19 20:57:47 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_db.h"

void ls_cleartree(t_dbnode **tree)
{
	t_dbnode		*tmp;

	tmp = *tree;
	if (!tree)
		return ;
	if (tmp->left)
		ls_cleartree(&tmp->left);
	if (tmp->right)
		ls_cleartree(&tmp->right);
	free(tmp);
	tree = NULL;
}

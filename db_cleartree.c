/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleartree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rlutt <rlutt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/12 19:07:26 by rlutt             #+#    #+#             */
/*   Updated: 2017/04/18 12:12:08 by rlutt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/ft_ls.h"

void ls_cleartree(t_node **tree)
{
	t_node		*tmp;

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

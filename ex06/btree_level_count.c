/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 16:22:41 by nhuber            #+#    #+#             */
/*   Updated: 2016/02/08 12:47:31 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int		btree_level_count(t_btree *root)
{
	int	lheight;
	int	rheight;

	if (root == NULL)
		return (-1);
	else
	{
		lheight = btree_level_count(root->left);
		rheight = btree_level_count(root->right);
		if (lheight > rheight)
			return (lheight + 1);
		else
			return (rheight + 1);
	}
}

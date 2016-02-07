/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_level_count.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 16:22:41 by nhuber            #+#    #+#             */
/*   Updated: 2016/02/07 18:58:55 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

int	btree_level_count(t_btree *root)
{
	int	lHeight;
	int	rHeight;

	if (root == NULL)
		return (-1);
	else
	{
		lHeight = btree_level_count(root->left);
		rHeight = btree_level_count(root->right);
		if (lHeight > rHeight)
			return (lHeight + 1);
		else 
			return (rHeight + 1);
	}
}

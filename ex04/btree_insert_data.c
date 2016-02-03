/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert_data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 15:03:09 by nhuber            #+#    #+#             */
/*   Updated: 2016/02/03 16:22:18 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	btree_insert_data(t_btree **root, void *item, int (*cmpf)(void *, void *))
{
	t_btree	*leaf;

	leaf = *root;
	if (leaf == NULL)
		leaf = btree_create_node(item);
	if (cmpf(leaf->item, item) == 0)
		return ;
	else if (cmpf(leaf->item, item) > 0)
		btree_insert_data(leaf->left, item, cmpf);
	else
		btree_insert_data(leaf->right, item, cmpf);
}

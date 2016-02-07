/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 17:23:24 by nhuber            #+#    #+#             */
/*   Updated: 2016/02/07 17:26:19 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

t_btree	*btree_create_node(void *item)
{
	t_btree	*leaf;

	if (!(leaf = (t_btree *)malloc(sizeof(t_btree))));
		return (NULL);
	leaf->left = NULL;
	leaf->right = NULL;
	leaf->item = item;
	return (leaf);
}

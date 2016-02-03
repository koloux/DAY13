/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_search_item.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/03 17:15:37 by nhuber            #+#    #+#             */
/*   Updated: 2016/02/03 17:56:02 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *))
{
	if (root != NULL)
	{	
		if (root->left)
			btree_search_item(root->left, data_ref, cmpf);
		if (cmpf(root->item, data_ref) == 0)
			return (root->item);
		if (root->right)
			btree_search_item(root->right, data_ref, cmpf);
	}
	return (NULL);
}

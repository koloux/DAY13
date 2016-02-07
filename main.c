/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nhuber <nhuber@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/05 14:23:57 by nhuber            #+#    #+#             */
/*   Updated: 2016/02/07 18:59:20 by nhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_btree.h"

#include <stdio.h>
int	ft_strcmp(void *str1, void *str2);
void	ft_putstr(void *str);

t_btree	*btree_create_node(void *item);

void	btree_apply_prefix(t_btree *root, void (*applyf)(void *));
void	btree_apply_infix(t_btree *root, void (*applyf)(void *));
void	btree_apply_suffix(t_btree *root, void (*applyf)(void *));

void	*btree_search_item(t_btree *root, void *data_ref, int (*cmpf)(void *, void *));

int	btree_level_count(t_btree *root);

int	main(int ac, char **av)
{
	t_btree	*leaf;
	char	*test = "test";

	leaf = btree_create_node(av[1]);
	leaf->left = btree_create_node(av[2]);
	leaf->right = btree_create_node(av[3]);
	leaf->left->right = btree_create_node(av[4]);
	leaf->left->left = btree_create_node(av[5]);
	
	printf("l'item : %s", btree_search_item(leaf, test, &ft_strcmp));
	printf("\n --------- \n");

	btree_apply_prefix(leaf, &ft_putstr);
	printf("\n --------- \n");
	btree_apply_infix(leaf, &ft_putstr);
	printf("\n --------- \n");
	btree_apply_suffix(leaf, &ft_putstr);
	printf("\n --------- \n");
	printf("level : %d\n", btree_level_count(leaf));	
	return (0);
}

void	ft_putstr(void *str)
{
	printf("the leaf : %s, ", str);
}

int	ft_strcmp(void *str1, void *str2)
{
	int i;

	i = 0;
	char *s1 = str1;
	char *s2 = str2;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:21:10 by abelov            #+#    #+#             */
/*   Updated: 2024/06/14 18:21:10 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	delete(t_pswap *pswap, char *to_remove)
{
	char	*tmp;
	size_t	index;

	while (ft_strstr(pswap->operations, to_remove) != NULL)
	{
		index = ft_strstr(pswap->operations, to_remove) - pswap->operations;
		tmp = ft_empty_string(ft_strlen(pswap->operations) - ft_strlen(to_remove));
		tmp = ft_strncpy(tmp, pswap->operations, index);
		tmp = ft_strcat(tmp, pswap->operations + index + ft_strlen(to_remove));
		free(pswap->operations);
		pswap->operations = tmp;
	}

	t_list *sub_list;
	sub_list = NULL;
	tmp = ft_strdup(to_remove);
	ft_list_push_front(&sub_list, ft_strdup(ft_strtok(tmp, "\n")));
	ft_list_push_front(&sub_list, ft_strdup(ft_strtok(NULL, "\n")));
	free(tmp);
	ft_list_remove_sublist(&pswap->ops, sub_list,
						   (int (*)(void *, void *)) ft_strcmp, free);
	ft_list_destroy(&sub_list, free);
}

void	delete_operations(t_pswap *pswap)
{
	delete(pswap, "\npa\npb");
	delete(pswap, "\npb\npa");
	delete(pswap, "\nra\nrra");
	delete(pswap, "\nrb\nrrb");
	delete(pswap, "\nrra\nra");
	delete(pswap, "\nrrb\nrb");
	delete(pswap, "\nsa\nsa");
	delete(pswap, "\nsb\nsb");
}

void	replace(t_pswap *pswap, char *long_op, char *short_op)
{
	char	*tmp;
	size_t	index;

	while (ft_strstr(pswap->operations, long_op) != NULL)
	{
		index = ft_strstr(pswap->operations, long_op) - pswap->operations;
		tmp = ft_empty_string(ft_strlen(pswap->operations) - ft_strlen(long_op)
							  + ft_strlen(short_op));
		tmp = ft_strncpy(tmp, pswap->operations, index);
		tmp = ft_strcat(tmp, short_op);
		tmp = ft_strcat(tmp, pswap->operations + index + ft_strlen(long_op));
		free(pswap->operations);
		pswap->operations = tmp;
	}

	t_list *to_find;
	t_list *to_replace_with;
	to_find = NULL;
	tmp = ft_strdup(long_op);
	ft_list_push_front(&to_find, ft_strdup(ft_strtok(tmp, "\n")));
	ft_list_push_front(&to_find, ft_strdup(ft_strtok(NULL, "\n")));
	free(tmp);
	tmp = ft_strdup(short_op);
	to_replace_with = ft_list_create_elem(ft_strdup(ft_strtok(tmp, "\n")));
	free(tmp);
	t_list_fun *const lst_fun = &(t_list_fun){
		.cmp_fun = (int (*)(void *, void *)) ft_strcmp,
		.del_fun = free,
		.dup_fun = (void *(*)(void *)) ft_strdup
	};
	ft_list_replace_sublist(&pswap->ops,
							to_find,
							to_replace_with,
							lst_fun);
	ft_list_destroy(&to_replace_with, free);
	ft_list_destroy(&to_find, free);
}

void	optimize(t_pswap *pswap)
{
	while (ft_strstr(pswap->operations, "\npa\npb") != NULL
		|| ft_strstr(pswap->operations, "\npb\npa") != NULL
		|| ft_strstr(pswap->operations, "\nra\nrra") != NULL
		|| ft_strstr(pswap->operations, "\nrb\nrrb") != NULL
		|| ft_strstr(pswap->operations, "\nrra\nra") != NULL
		|| ft_strstr(pswap->operations, "\nrrb\nrb") != NULL
		|| ft_strstr(pswap->operations, "\nsa\nsa") != NULL
		|| ft_strstr(pswap->operations, "\nsb\nsb") != NULL)
		delete_operations(pswap);
	replace(pswap, "\nsa\nsb\n", "\nss\n");
	replace(pswap, "\nsb\nsa\n", "\nss\n");
	replace(pswap, "\nrra\nrrb\n", "\nrrr\n");
	replace(pswap, "\nrrb\nrra\n", "\nrrr\n");
	replace(pswap, "\nra\nrb\n", "\nrr\n");
	replace(pswap, "\nrb\nra\n", "\nrr\n");
}

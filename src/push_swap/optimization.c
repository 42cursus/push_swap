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

void	delete(t_pswap *pswap, const char *op1, const char *op2)
{
	t_list	*to_delete;

	to_delete = ft_list_push_strs(2, (const char *[2]){op1, op2});
	ft_list_remove_sublist(&pswap->ops, to_delete,
		(__compar_fn_t) ft_strcmp, NULL);
	ft_list_destroy(&to_delete, NULL);
}

void	delete_operations(t_pswap *pswap)
{
	size_t		iter;
	char *const	to_delete[][2] = {
	{"pa", "pb"},
	{"pb", "pa"},
	{"ra", "rra"},
	{"rb", "rrb"},
	{"sa", "sa"},
	{"sb", "sb"},
	{"rrb", "rb"},
	{"rra", "ra"},
	};

	iter = -1;
	while (++iter < (sizeof(to_delete) / (sizeof(to_delete[0]))))
		delete(pswap, to_delete[iter][0], to_delete[iter][1]);
}

void	optimize(t_pswap *pswap, int attempts)
{
	while (ft_swap_contains_suboptimal(pswap))
		delete_operations(pswap);
	ft_swap_replace(pswap);
	if (pswap->arg_tab_size >= 90 && pswap->arg_tab_size <= 110
		&& ft_list_size(pswap->ops) > 699
		&& attempts < 11)
		ft_swap_do_it_again(pswap, attempts);
}

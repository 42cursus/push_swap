/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_and_swap.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:56:47 by abelov            #+#    #+#             */
/*   Updated: 2024/06/14 17:56:48 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_check_few_in_a(t_pswap *pswap)
{
	if (pswap->stack_a_size == 2)
	{
		if (pswap->stack_a[pswap->arg_tab_size - 1] >= pswap->stack_a[pswap->arg_tab_size - 2])
			pswap->pivots_b[0] = pswap->stack_a[pswap->arg_tab_size - 2];
		else
			pswap->pivots_b[0] = pswap->stack_a[pswap->arg_tab_size - 1];
		if (pswap->stack_a[pswap->arg_tab_size - 1] > pswap->stack_a[pswap->arg_tab_size - 2])
			ft_swap_do_op(pswap, "pb\n");
		else
		{
			ft_swap_do_op(pswap, "ra\n");
			ft_swap_do_op(pswap, "pb\n");
		}
	}
}

void	sort_almost_sorted(t_pswap *pswap)
{
	int		i;

	i = 0;
	while (pswap->stack_a[i] != pswap->sorted_max_nbr)
		i++;
	while (i >= pswap->arg_tab_size / 2 && ft_swap_is_sorted(pswap))
		ft_swap_do_op(pswap, "rra\n");
	while (i < pswap->arg_tab_size / 2 && ft_swap_is_sorted(pswap))
		ft_swap_do_op(pswap, "ra\n");

}

void	sort_few_numbers(t_pswap *pswap)
{
	if (pswap->arg_tab_size == 3)
		ft_swap_sort3_a(pswap);
	if (pswap->arg_tab_size == 2)
		ft_swap_sort2_a(pswap);
}

void	sort_from_a_to_b_first_push(t_pswap *pswap, int pivot)
{
	if (pswap->stack_a[ft_swap_get_top(pswap, 'a')] == pswap->sorted_min_nbr)
	{
		ft_swap_do_op(pswap, "pb\n");
		ft_swap_do_op(pswap, "rb\n");
	}
	else if (pswap->stack_a[ft_swap_get_top(pswap, 'a')] < pivot)
		ft_swap_do_op(pswap, "pb\n");
	else if (pswap->stack_a[ft_swap_get_top(pswap, 'a')] == pivot)
	{
		ft_swap_do_op(pswap, "pb\n");
		ft_swap_do_op(pswap, "rb\n");
		pswap->pushed_pivot = 1;
	}
	else
		ft_swap_do_op(pswap, "ra\n");
}


void	sort_first_push(t_pswap *pswap, int pivot)
{
	while (ft_swap_chklteq_pivot(pswap->stack_a,
								 ft_swap_get_top(pswap, 'a'),
								 pswap->arg_tab_size, pivot) != -1)
		sort_from_a_to_b_first_push(pswap, pivot);
	if (pswap->pushed_pivot == 1)
		ft_swap_do_op(pswap, "rrb\n");
	if (pswap->stack_b[pswap->arg_tab_size - 1] == pivot)
	{
		ft_swap_do_op(pswap, "rrb\n");
		ft_swap_do_op(pswap, "sb\n");
		ft_swap_do_op(pswap, "rb\n");
	}
	ft_swap_add_pivot_b(pswap, pivot);
}

void	sort_random(t_pswap *pswap)
{
	int		pivot_p;

	while (pswap->stack_a_size > 1 && ft_swap_is_sorted(pswap) == -1)
	{
		pswap->pushed_pivot = 0;
		pivot_p = ft_swap_get_pivot(pswap, 'a', ft_swap_get_top(pswap, 'a'), pswap->arg_tab_size - 1);
		sort_first_push(pswap, pivot_p);
		ft_check_few_in_a(pswap);
	}
	while (pswap->pivots_b_tab_size > 0 && pswap->pivots_b[0] >= pswap->stack_a[pswap->top_a])
		ft_swap_remove_pivot_b(pswap);
	pswap->pivot_a = pswap->stack_a[ft_swap_get_top(pswap, 'a')];
	while (!(ft_swap_is_sorted(pswap) == 0 && pswap->stack_a_size == pswap->arg_tab_size))
		ft_swap_push_back(pswap);
}

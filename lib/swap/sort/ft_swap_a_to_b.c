/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_a_to_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:00:27 by abelov            #+#    #+#             */
/*   Updated: 2024/06/15 20:00:28 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

void ft_swap_push_a_to_b(t_pswap *pswap)
{
	int		pivot;
	int		count_rotations;
	int		top_in_a;
	int		pivot_index;

	top_in_a = ft_swap_get_top(pswap, 'a');
	pivot_index = ft_swap_get_pivot_index(pswap, 'a');
	pivot = ft_swap_get_pivot(pswap, 'a', top_in_a, pivot_index);
	while ((ft_swap_get_pivot_index(pswap, 'a') - pswap->top_a > 1)
		   && ft_swap_is_sorted(pswap) == -1)
	{
		pswap->pushed_pivot = 0;
		count_rotations = ft_swap_sort_a_to_b(pswap, pivot, 0);
		ft_swap_rot_pivot_min(pswap, pivot, count_rotations);
		pivot_index = ft_swap_get_pivot_index(pswap, 'a');
		top_in_a = ft_swap_get_top(pswap, 'a');
		if (pswap->stack_a_size && (pivot_index - top_in_a) > 1)
		{
			ft_swap_do_op(pswap, pb);
			ft_swap_add_pivot_b(pswap, pivot);
		}
	}
	if (pswap->stack_a_size)
		pswap->pivot_a = ft_swap_pivot_a(pswap);
}

int ft_swap_sort_a_to_b(t_pswap *pswap, int pivot, int count_rotations)
{
	pswap->pivot_a = ft_swap_pivot_a(pswap);
	while (pswap->stack_a_size
		&& pswap->stack_a[pswap->top_a] != pswap->pivot_a)
	{
		if (pswap->top_a != 0 && pswap->stack_a[pswap->top_a] <= pivot
			&& pivot != pswap->sorted[ft_swap_get_pivot_index(pswap, 'a') - 1])
			ft_swap_lteq_pivot(pswap, pivot);
		else
		{
			ft_swap_do_op(pswap, ra);
			count_rotations++;
		}
	}
	ft_swap_rotate_pivot_b(pswap);
	if (pswap->stack_a_size)
		pswap->pivot_a = ft_swap_pivot_a(pswap);
	ft_swap_chktop_both_stacks(pswap);
	return (count_rotations);
}

void ft_swap_rot_pivot_min(t_pswap *pswap, int pivot, int rotations)
{
	int		index_max;

	ft_swap_rotate_pivot_b(pswap);
	if (pswap->stack_b[pswap->arg_tab_size - 1] != pivot
		&& pswap->stack_b[pswap->arg_tab_size - 1] != pswap->sorted_min_nbr)
	{
		ft_swap_do_op(pswap, rrb);
		ft_swap_do_op(pswap, sb);
		ft_swap_do_op(pswap, rb);
		ft_swap_add_pivot_b(pswap, pswap->stack_b[pswap->top_b]);
	}
	pswap->pushed_pivot = 0;
	index_max = ft_tab_int_get_index(pswap->stack_a, pswap->top_a,
									 pswap->arg_tab_size - 1,
									 pswap->sorted_max_nbr) + 1;
	pivot = ft_swap_get_pivot(pswap, 'a', index_max, pswap->arg_tab_size - 1);
	while (rotations--)
	{
		ft_swap_do_op(pswap, rra);
		if (pswap->stack_a[pswap->top_a] <= pivot)
			ft_swap_lteq_pivot(pswap, pivot);
		ft_swap_chktop_both_stacks(pswap);
		if (pswap->stack_b[pswap->arg_tab_size - 1] == pivot)
			ft_swap_rotate_pivot_b(pswap);
	}
}

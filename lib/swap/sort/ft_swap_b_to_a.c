/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_b_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:00:33 by abelov            #+#    #+#             */
/*   Updated: 2024/06/15 20:00:34 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

void	ft_swap_push_back_in_order(t_pswap *pswap)
{
	while (pswap->stack_b_size && pswap->stack_b[pswap->top_b] == pswap->sorted[pswap->top_a - 1])
	{
		if (pswap->pivots_b_tab_size > 0 && pswap->stack_b[pswap->top_b] == pswap->pivots_b[0])
			ft_swap_remove_pivot_b(pswap);
		ft_swap_do_op(pswap, pa);
		pswap->pivot_a = pswap->stack_a[pswap->top_a];
	}
}

int ft_swap_get_curr_pivot_b(t_pswap *pswap)
{
	int		curr_pivot;

	if (pswap->pivots_b_tab_size < 2)
	{
		curr_pivot = ft_swap_get_pivot(pswap, 'b', pswap->top_b, pswap->arg_tab_size - 1);
		ft_swap_add_pivot_b(pswap, curr_pivot);
	}
	else
	{
		curr_pivot = ft_swap_get_pivot(pswap, 'b', pswap->top_b, ft_swap_get_pivot_index(pswap, 'b') - 1);
		if (curr_pivot < pswap->pivots_b[0])
		{
			curr_pivot = pswap->pivots_b[0];
			ft_swap_remove_pivot_b(pswap);
		}
	}
	return (curr_pivot);
}

void	ft_swap_push_b_to_a(t_pswap *pswap, int pivot, int *count_rotate)
{
	if (pswap->stack_b[pswap->top_b] >= pivot)
	{
		ft_swap_do_op(pswap, pa);
		if (pswap->stack_a[pswap->top_a] == pivot)
		{
			ft_swap_do_op(pswap, ra);
			pswap->pushed_pivot = 1;
		}
		if (pswap->stack_a[pswap->top_a] > pswap->stack_a[pswap->top_a + 1])
			ft_swap_do_op(pswap, sa);
		pswap->pivot_a = ft_swap_pivot_a(pswap);
	}
	else if (pswap->stack_b_size > 1)
	{
		ft_swap_do_op(pswap, rb);
		(*count_rotate)++;
	}
}

void	ft_swap_rotrev(t_pswap *pswap, int count_rotate)
{
	if (count_rotate > pswap->stack_b_size / 2)
		ft_swap_do_op(pswap, rb);
	else
		while (count_rotate--)
			ft_swap_do_op(pswap, rrb);
}

void	ft_swap_sort_b_to_a(t_pswap *pswap, int pivot)
{
	int		count_rotate;

	count_rotate = 0;
	while (pswap->stack_b[pswap->top_b] != pswap->pivots_b[0]
			&& pswap->stack_b_size > 0)
		ft_swap_push_b_to_a(pswap, pivot, &count_rotate);
	ft_swap_rotrev(pswap, count_rotate);
	if (pswap->pushed_pivot == 1)
	{
		ft_swap_do_op(pswap, rra);
		if (ft_swap_is_sorted(pswap) != 0)
		{
			ft_swap_do_op(pswap, pb);
			ft_swap_add_pivot_b(pswap, pivot);
		}
		if (pswap->stack_a[pswap->top_a] > pswap->stack_a[pswap->top_a + 1])
			ft_swap_do_op(pswap, sa);
		pswap->pivot_a = ft_swap_pivot_a(pswap);
	}
}

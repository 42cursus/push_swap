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
	int	last_in_a;
	int	prev_to_last_in_a;

	if (pswap->stack_a_size == 2)
	{
		last_in_a = pswap->stack_a[pswap->arg_tab_size - 1];
		prev_to_last_in_a = pswap->stack_a[pswap->arg_tab_size - 2];
		if (last_in_a >= prev_to_last_in_a)
			pswap->pivots_b[0] = prev_to_last_in_a;
		else
			pswap->pivots_b[0] = last_in_a;
		last_in_a = pswap->stack_a[pswap->arg_tab_size - 1];
		prev_to_last_in_a = pswap->stack_a[pswap->arg_tab_size - 2];
		if (last_in_a > prev_to_last_in_a)
			ft_swap_do_op(pswap, pb);
		else
		{
			ft_swap_do_op(pswap, pa);
			ft_swap_do_op(pswap, pb);
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
		ft_swap_do_op(pswap, rra);
	while (i < pswap->arg_tab_size / 2 && ft_swap_is_sorted(pswap))
		ft_swap_do_op(pswap, ra);
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
	int	top_in_a;

	top_in_a = ft_swap_get_top(pswap, 'a');
	if (pswap->stack_a[top_in_a] == pswap->sorted_min_nbr)
	{
		ft_swap_do_op(pswap, pb);
		ft_swap_do_op(pswap, rb);
	}
	else if (pswap->stack_a[top_in_a] < pivot)
		ft_swap_do_op(pswap, pb);
	else if (pswap->stack_a[top_in_a] == pivot)
	{
		ft_swap_do_op(pswap, pb);
		ft_swap_do_op(pswap, rb);
		pswap->pushed_pivot = 1;
	}
	else
		ft_swap_do_op(pswap, ra);
}

void	ft_swap_sort_first_push(t_pswap *pswap, int pivot)
{
	while (ft_swap_chklteq_pivot(pswap->stack_a, ft_swap_get_top(pswap, 'a'),
			pswap->arg_tab_size, pivot) != -1)
		sort_from_a_to_b_first_push(pswap, pivot);
	if (pswap->pushed_pivot == 1)
		ft_swap_do_op(pswap, rrb);
	if (pswap->stack_b[pswap->arg_tab_size - 1] == pivot)
	{
		ft_swap_do_op(pswap, rrb);
		ft_swap_do_op(pswap, sb);
		ft_swap_do_op(pswap, rb);
	}
	ft_swap_add_pivot_b(pswap, pivot);
}

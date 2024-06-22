/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_pivot_ops.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 23:08:57 by abelov            #+#    #+#             */
/*   Updated: 2024/06/15 17:40:00 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pswap.h>
#include "libswap.h"

/**
 * Finds pivot point in the stack
 */
int	ft_swap_get_pivot_index(t_pswap *pswap, char stack)
{
	int	i;

	i = 0;
	if (stack == 'a')
	{
		i = pswap->top_a;
		while (i < pswap->arg_tab_size - 1
			&& pswap->stack_a[i] != pswap->pivot_a)
			i++;
		if (i == pswap->arg_tab_size - 1
			&& pswap->stack_a[i] == pswap->pivot_a)
			return (i);
	}
	else if (stack == 'b')
	{
		i = pswap->top_b;
		while (i < pswap->arg_tab_size - 1
			&& pswap->stack_b[i] != pswap->pivots_b[0])
			i++;
		if (i == pswap->arg_tab_size - 1
			&& pswap->stack_b[i] == pswap->pivots_b[0])
			return (i);
	}
	return (i);
}

void	ft_swap_remove_pivot_b(t_pswap *pswap)
{
	int		*out;

	out = ft_tab_int_init(pswap->pivots_b_tab_size - 1);
	out = ft_copy_int_tab(pswap->pivots_b, out,
			1, pswap->pivots_b_tab_size - 1);
	free(pswap->pivots_b);
	pswap->pivots_b = out;
	if (pswap->pivots_b_tab_size > 0)
		pswap->pivots_b_tab_size -= 1;
}

int	ft_swap_get_pivot(t_pswap *pswap, char stack_name, int first, int last)
{
	int		*sorted;
	int		ret;
	int		*stack;

	stack = pswap->stack_a;
	if (stack_name == 'b')
		stack = pswap->stack_b;
	if (last <= first && stack_name == 'b' && pswap->pivots_b_tab_size > 0)
	{
		ft_swap_remove_pivot_b(pswap);
		return (ft_swap_get_pivot(pswap, 'b',
				pswap->top_b, ft_swap_get_pivot_index(pswap, 'b') - 1));
	}
	sorted = ft_tab_int_init(last - first + 1);
	sorted = ft_copy_int_tab(stack, sorted, first, last);
	sorted = ft_sort_int_tab(sorted, last - first + 1);
	ret = sorted[(last - first) / 2];
	free(sorted);
	return (ret);
}

void	ft_swap_lteq_pivot(t_pswap *pswap, int pivot)
{
	ft_swap_do_op(pswap, pb);
	if (pswap->stack_b[pswap->top_b] == pswap->sorted_min_nbr)
		ft_swap_do_op(pswap, rb);
	else if (pswap->stack_b[pswap->top_b] == pivot)
	{
		ft_swap_do_op(pswap, rb);
		pswap->pushed_pivot = 1;
	}
	if (pswap->stack_b[pswap->top_b] < pswap->stack_b[pswap->top_b + 1])
		ft_swap_do_op(pswap, sb);
}

/**
 * Check that there are still numbers lteq pivot in the stack
 */
int	ft_swap_chklteq_pivot(int const *tab, int top, int tab_len, int pivot)
{
	int	i;

	i = top;
	while (i < tab_len)
	{
		if (tab[i] <= pivot)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_swap_chkgt_pivot(int const *tab, int first, int last, int pibon)
{
	int	i;

	i = first;
	while (i < last)
	{
		if (tab[i] > pibon)
			return (i);
		i++;
	}
	return (-1);
}

void	ft_swap_add_pivot_b(t_pswap *pswap, int pivot)
{
	int	i;
	int	*out;

	i = 1;
	if (ft_swap_chkgt_pivot(pswap->stack_b, pswap->top_b,
			pswap->arg_tab_size - 1, pivot) != -1)
		return ;
	out = ft_tab_int_init(pswap->pivots_b_tab_size + 1);
	if (!out)
		return ;
	out[0] = pivot;
	while (i < pswap->pivots_b_tab_size + 1)
	{
		out[i] = pswap->pivots_b[i - 1];
		i++;
	}
	free(pswap->pivots_b);
	pswap->pivots_b = out;
	pswap->pivots_b_tab_size += 1;
}

int	ft_swap_pivot_a(t_pswap *pswap)
{
	int	i;
	int	ret_val;

	i = pswap->arg_tab_size - 1;
	while (i > pswap->top_a)
	{
		if (pswap->stack_a[i] != pswap->sorted[i])
			break ;
		else
			i--;
		if (i == pswap->top_a && pswap->stack_a[i] == pswap->sorted[i])
			return (pswap->stack_a[pswap->top_a]);
	}
	ret_val = 0;
	if (i != pswap->arg_tab_size - 1)
		ret_val = pswap->stack_a[i + 1];
	return (ret_val);
}

void	ft_swap_rotate_pivot_b(t_pswap *pswap)
{
	if (pswap->pushed_pivot == 1
		&& pswap->stack_b[pswap->arg_tab_size - 1] != pswap->sorted_min_nbr)
	{
		ft_swap_do_op(pswap, rrb);
		ft_swap_add_pivot_b(pswap, pswap->stack_b[pswap->top_b]);
	}
}

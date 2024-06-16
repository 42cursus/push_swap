/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:53:55 by abelov            #+#    #+#             */
/*   Updated: 2024/06/15 20:53:56 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

void ft_swap_sort2_a(t_pswap *pswap)
{
	int		top;

	top = pswap->top_a;
	if (pswap->stack_a[top] < pswap->stack_a[top + 1])
		ft_swap_do_op(pswap, "sa\n");
}


void ft_swap_sort3_a(t_pswap *pswap)
{
	while (!(pswap->stack_a[pswap->top_a] < pswap->stack_a[pswap->top_a + 1]
			 && pswap->stack_a[pswap->top_a + 1] < pswap->stack_a[pswap->top_a + 2]))
	{
		if (pswap->stack_a[pswap->top_a] < pswap->stack_a[pswap->top_a + 1])
			ft_swap_do_op(pswap, "rra\n");
		else if (pswap->stack_a[pswap->top_a] > pswap->stack_a[pswap->top_a + 1]
				 && pswap->stack_a[pswap->top_a] > pswap->stack_a[pswap->top_a + 2])
			ft_swap_do_op(pswap, "ra\n");
		else
			ft_swap_do_op(pswap, "sa\n");
	}
}


void ft_swap_sort2_b(t_pswap *pswap)
{
	int		top;

	top = pswap->top_b;
	if (pswap->stack_b[top] < pswap->stack_b[top + 1])
		ft_swap_do_op(pswap, "sb\n");
	ft_swap_do_op(pswap, "pa\n");
	ft_swap_do_op(pswap, "pa\n");
}

void ft_swap_sort3_b(t_pswap *pswap)
{
	while (!(pswap->stack_b[pswap->top_b] > pswap->stack_b[pswap->top_b + 1]
			 && pswap->stack_b[pswap->top_b + 1] > pswap->stack_b[pswap->top_b + 2]))
	{
		if (pswap->stack_b[pswap->top_b] < pswap->stack_b[pswap->top_b + 1])
			ft_swap_do_op(pswap, "rb\n");
		else if (pswap->stack_b[pswap->top_b] > pswap->stack_b[pswap->top_b + 2])
			ft_swap_do_op(pswap, "sb\n");
		else
			ft_swap_do_op(pswap, "rrb\n");
	}
	ft_swap_do_op(pswap, "pa\n");
	ft_swap_do_op(pswap, "pa\n");
	ft_swap_do_op(pswap, "pa\n");
}

void ft_swap_lt_four_nbrs_stack_b(t_pswap *pswap)
{
	if (pswap->stack_b_size == 3)
		ft_swap_sort3_b(pswap);
	if (pswap->stack_b_size == 2)
		ft_swap_sort2_b(pswap);
	else
		ft_swap_do_op(pswap, "pa\n");
}

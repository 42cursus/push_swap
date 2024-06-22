/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_do_rotate_op.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 22:49:01 by abelov            #+#    #+#             */
/*   Updated: 2024/06/22 22:49:01 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

void	ft_swap_do_pa_op(t_pswap *pswap)
{
	int	top_in_a;
	int	top_in_b;

	if (pswap->stack_b_size > 0)
	{
		top_in_a = ft_swap_get_top(pswap, 'a');
		top_in_b = ft_swap_get_top(pswap, 'b');
		pswap->stack_a[top_in_a - 1] = pswap->stack_b[top_in_b];
		pswap->stack_b[ft_swap_get_top(pswap, 'b')] = 0;
		pswap->stack_b_size--;
		pswap->stack_a_size++;
		pswap->top_a = ft_swap_get_top(pswap, 'a');
		pswap->top_b = ft_swap_get_top(pswap, 'b');
	}
}

void	ft_swap_do_pb_op(t_pswap *pswap)
{
	int	top_in_a;
	int	top_in_b;

	if (pswap->stack_a_size > 0)
	{
		top_in_a = ft_swap_get_top(pswap, 'a');
		top_in_b = ft_swap_get_top(pswap, 'b');
		pswap->stack_b[top_in_b - 1] = pswap->stack_a[top_in_a];
		pswap->stack_a[top_in_a] = 0;
		pswap->stack_a_size--;
		pswap->stack_b_size++;
		pswap->top_a = ft_swap_get_top(pswap, 'a');
		pswap->top_b = ft_swap_get_top(pswap, 'b');
	}
}

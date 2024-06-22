/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_do_swap_op.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 22:49:01 by abelov            #+#    #+#             */
/*   Updated: 2024/06/22 23:34:58 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

void	ft_swap_do_sb_op(t_pswap *pswap)
{
	int	swap;
	int	top_b;

	if (pswap->stack_b_size > 1)
	{
		top_b = ft_swap_get_top(pswap, 'b');
		swap = pswap->stack_b[top_b];
		pswap->stack_b[top_b] = pswap->stack_b[top_b + 1];
		pswap->stack_b[top_b + 1] = swap;
	}
}

void	ft_swap_do_sa_op(t_pswap *pswap)
{
	int	swap;
	int	top_a;

	if (pswap->stack_a_size > 1)
	{
		top_a = ft_swap_get_top(pswap, 'a');
		swap = pswap->stack_a[top_a];
		pswap->stack_a[top_a] = pswap->stack_a[top_a + 1];
		pswap->stack_a[top_a + 1] = swap;
	}
}

void	ft_swap_do_ss_op(t_pswap *pswap)
{
	ft_swap_do_sa_op(pswap);
	ft_swap_do_sb_op(pswap);
}

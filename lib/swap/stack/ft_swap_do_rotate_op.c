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

void	ft_swap_do_ra_op(t_pswap *pswap)
{
	int	topnb;
	int	first;

	if (pswap->stack_a_size > 0)
	{
		topnb = ft_swap_get_top(pswap, 'a');
		first = pswap->stack_a[topnb];
		while (++(topnb) < pswap->arg_tab_size)
			pswap->stack_a[topnb - 1] = pswap->stack_a[topnb];
		pswap->stack_a[pswap->arg_tab_size - 1] = first;
	}
}

void	ft_swap_do_rb_op(t_pswap *pswap)
{
	int	topnb;
	int	first;

	if (pswap->stack_b_size > 0)
	{
		topnb = ft_swap_get_top(pswap, 'b');
		first = pswap->stack_b[topnb];
		while (++(topnb) < pswap->arg_tab_size)
			pswap->stack_b[topnb - 1] = pswap->stack_b[topnb];
		pswap->stack_b[pswap->arg_tab_size - 1] = first;
	}
}

void	ft_swap_do_rr_op(t_pswap *pswap)
{
	ft_swap_do_ra_op(pswap);
	ft_swap_do_rb_op(pswap);
}

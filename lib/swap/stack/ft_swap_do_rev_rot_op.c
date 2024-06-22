/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_do_rev_rot_op.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 22:49:01 by abelov            #+#    #+#             */
/*   Updated: 2024/06/22 22:49:52 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

void	ft_swap_do_rra_op(t_pswap *pswap)
{
	int	i;
	int	last;

	if (pswap->stack_a_size > 0)
	{
		i = pswap->arg_tab_size - 1;
		last = pswap->stack_a[pswap->arg_tab_size - 1];
		while (--i + 1 > ft_swap_get_top(pswap, 'a'))
			pswap->stack_a[i + 1] = pswap->stack_a[i];
		pswap->stack_a[ft_swap_get_top(pswap, 'a')] = last;
	}
}

void	ft_swap_do_rrb_op(t_pswap *pswap)
{
	int	i;
	int	last;

	if (pswap->stack_b_size > 0)
	{
		i = pswap->arg_tab_size - 1;
		last = pswap->stack_b[pswap->arg_tab_size - 1];
		while (--i + 1 > ft_swap_get_top(pswap, 'b'))
			pswap->stack_b[i + 1] = pswap->stack_b[i];
		pswap->stack_b[ft_swap_get_top(pswap, 'b')] = last;
	}
}

void	ft_swap_do_rrr_op(t_pswap *pswap)
{
	ft_swap_do_rra_op(pswap);
	ft_swap_do_rrb_op(pswap);
}

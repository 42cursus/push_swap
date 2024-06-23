/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_push_to.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 20:02:11 by abelov            #+#    #+#             */
/*   Updated: 2024/06/15 20:02:12 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

int	ft_swap_push_back(t_pswap *pswap)
{
	pswap->pivot_b = 0;
	pswap->pushed_pivot = 0;
	if (pswap->stack_b_size == 0
		&& ft_swap_is_sorted(pswap) == 0 && pswap->top_a == 0)
		return (0);
	if (pswap->stack_b_size < 4 && pswap->stack_b_size > 0)
		ft_swap_lt_four_nbrs_stack_b(pswap);
	ft_swap_push_back_in_order(pswap);
	if (pswap->stack_b_size)
	{
		pswap->pivot_b = ft_swap_get_curr_pivot_b(pswap);
		ft_swap_sort_b_to_a(pswap, pswap->pivot_b);
		if (pswap->stack_b_size < 4 && pswap->stack_b_size > 0)
		{
			ft_swap_lt_four_nbrs_stack_b(pswap);
			if (ft_swap_is_sorted(pswap) == 0)
			{
				pswap->pivot_a = ft_swap_pivot_a(pswap);
				return (0);
			}
		}
	}
	if (pswap->stack_a_size)
		pswap->pivot_a = ft_swap_pivot_a(pswap);
	return (ft_swap_push_to(pswap));
}

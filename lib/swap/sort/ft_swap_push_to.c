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

int ft_swap_push_to(t_pswap *pswap)
{
	while (!(ft_swap_is_sorted(pswap) == 0
			&& pswap->stack_a_size == pswap->arg_tab_size))
	{
		if (pswap->stack_a_size)
		{
			pswap->pivot_a = ft_swap_pivot_a(pswap);
			ft_swap_push_a_to_b(pswap);
			while (pswap->pivots_b_tab_size > 0
					&& pswap->pivots_b[0] >= pswap->stack_a[pswap->top_a])
				ft_swap_remove_pivot_b(pswap);
		}
		ft_swap_push_back(pswap);
	}
	return (0);
}

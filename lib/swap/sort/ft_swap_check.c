/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pswap_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:01:02 by abelov            #+#    #+#             */
/*   Updated: 2024/06/14 18:01:02 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

int	ft_swap_is_sorted(t_pswap *pswap)
{
	int		i;

	i = pswap->top_a - 1;
	while (++i < pswap->arg_tab_size)
		if (pswap->stack_a[i] != pswap->sorted[i])
			return (-1);
	return (0);
}

int	ft_swap_is_almost_sorted(t_pswap *pswap)
{
	int		i;

	i = 0;
	while (pswap->stack_a[i] < pswap->stack_a[i + 1])
		i++;
	if (pswap->stack_a[i] != pswap->sorted_max_nbr || pswap->stack_a[i + 1] != pswap->sorted_min_nbr)
		return (-1);
	i++;
	while (i < pswap->arg_tab_size - 1 && pswap->stack_a[i] < pswap->stack_a[i + 1])
		i++;
	if (i == pswap->arg_tab_size - 1 && pswap->stack_a[i] < pswap->stack_a[0])
		return (1);
	return (-1);
}

void ft_swap_chktop_both_stacks(t_pswap *pswap)
{
	if (pswap->stack_a[pswap->top_a] > pswap->stack_a[pswap->top_a + 1])
		ft_swap_do_op(pswap, "sa\n");
	if (pswap->stack_b[pswap->top_b] < pswap->stack_b[pswap->top_b + 1])
		ft_swap_do_op(pswap, "sb\n");
}

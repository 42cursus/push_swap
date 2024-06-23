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

#include "libswap.h"

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

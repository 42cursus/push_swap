/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_draw_ascii.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:41:26 by abelov            #+#    #+#             */
/*   Updated: 2024/06/15 23:23:04 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

int ft_swap_print_a(t_pswap *pswap, int idx)
{
	int		nblen;
	char	*fmt;
	char	*const buf = (char[INT_MIN_LEN + 1]){[0 ... INT_MIN_LEN] = ' '};

	nblen = ft_nblen(pswap->stack_a[idx]);
	if ((pswap->pivot_a == pswap->stack_a[idx]) && (pswap->top_a <= idx))
		fmt = "│     * %d%s";
	else
		fmt = "│       %d%s";
	buf[INT_MIN_LEN - nblen] = '\0';
	ft_printf(fmt, pswap->stack_a[idx], buf);
	return idx;
}

int ft_swap_print_b(t_pswap *pswap, int idx)
{
	char	*fmt;
	int		nblen;
	int		is_pivot;
	char	*const buf = (char[INT_MIN_LEN + 1]){[0 ... INT_MIN_LEN] = ' '};

	nblen = ft_nblen(pswap->stack_b[idx]);
	is_pivot = ft_tab_int_contains(pswap->pivots_b, pswap->pivots_b_tab_size,
								   pswap->stack_b[idx]);
	if ((is_pivot != -1) && (pswap->top_b <= idx))
		fmt = "│     * %d%s";
	else
		fmt = "│       %d%s";
	buf[INT_MIN_LEN - nblen] = '\0';
	ft_printf(fmt, pswap->stack_b[idx], buf);
	ft_putstr_eol("│","\n");
	return idx;
}


void ft_swap_draw_ascii(t_pswap *pswap)
{
	int	iter;

	iter = -1;
	if (pswap->debug == 1)
	{
		ft_putstr_eol("┌──────────────────┬──────────────────┐", "\n");
		ft_putstr_eol("│     stack a      │     stack b      │", "\n");
		ft_putstr_eol("│‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾│‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾│", "\n");
		while (++iter < pswap->arg_tab_size)
		{
			iter = ft_swap_print_a(pswap, iter);
			iter = ft_swap_print_b(pswap, iter);
		}
		ft_putstr_eol("└──────────────────┴──────────────────┘", "\n\n");
	}
}

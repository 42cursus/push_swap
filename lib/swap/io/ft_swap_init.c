/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:24:42 by abelov            #+#    #+#             */
/*   Updated: 2024/06/24 16:24:43 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libswap.h"

void	init_swap_ops(t_swap_op **swap_ops, int *size)
{
	static t_swap_op	ops[] = {
	{.opcode = sa, .fun = ft_swap_do_sa_op},
	{.opcode = sb, .fun = ft_swap_do_sb_op},
	{.opcode = ss, .fun = ft_swap_do_ss_op},
	{.opcode = pa, .fun = ft_swap_do_pa_op},
	{.opcode = pb, .fun = ft_swap_do_pb_op},
	{.opcode = ra, .fun = ft_swap_do_ra_op},
	{.opcode = rb, .fun = ft_swap_do_rb_op},
	{.opcode = rr, .fun = ft_swap_do_rr_op},
	{.opcode = rra, .fun = ft_swap_do_rra_op},
	{.opcode = rrb, .fun = ft_swap_do_rrb_op},
	{.opcode = rrr, .fun = ft_swap_do_rrr_op}
	};

	*swap_ops = ops;
	*size = sizeof(ops) / sizeof(ops[0]);
	ft_qsort(ops, *size, sizeof(ops[0]), ft_swap_op_cmp);
}

void	init_suboptimal_ops(const char *(**ptr)[2], int *size)
{
	static const char	*ops[][2] = {
	{"pa", "pb"},
	{"pb", "pa"},
	{"ra", "rra"},
	{"rra", "ra"},
	{"rb", "rrb"},
	{"rrb", "rb"},
	{"sa", "sa"},
	{"sb", "sb"}
	};

	*ptr = ops;
	*size = sizeof(ops) / (sizeof(ops[0]));
}

void	ft_swap_init_stack_a(t_pswap *pswap)
{
	if (pswap->arg_tab)
	{
		pswap->stack_a = ft_tab_int_init(pswap->arg_tab_size);
		pswap->stack_b = ft_tab_int_init(pswap->arg_tab_size);
	}
	ft_memcpy(pswap->stack_a, pswap->arg_tab,
		sizeof(int) * pswap->arg_tab_size);
}

void	ft_swap_init(t_pswap *pswap)
{
	ft_swap_init_stack_a(pswap);
	pswap->sorted = ft_tab_int_init(pswap->arg_tab_size);
	pswap->sorted = ft_copy_int_tab(pswap->stack_a, pswap->sorted, 0,
			pswap->arg_tab_size - 1);
	pswap->sorted = ft_sort_int_tab(pswap->sorted, pswap->arg_tab_size);
	pswap->sorted_min_nbr = pswap->sorted[0];
	pswap->sorted_max_nbr = pswap->sorted[pswap->arg_tab_size - 1];
	pswap->stack_a_size = pswap->arg_tab_size;
	pswap->stack_b_size = 0;
	if (pswap->stack_a)
		pswap->pivot_a = pswap->stack_a[pswap->arg_tab_size - 1];
	pswap->pivots_b = ft_tab_int_init(1);
	pswap->pivots_b_tab_size = 1;
	*pswap->pivots_b = pswap->sorted_min_nbr;
	pswap->pushed_pivot = 0;
	pswap->top_a = ft_swap_get_top(pswap, 'a');
	pswap->top_b = ft_swap_get_top(pswap, 'b');
	pswap->operations = ft_strnew(1);
	pswap->ops = NULL;
	init_swap_ops(&pswap->swap_ops, &pswap->swap_ops_size);
	init_suboptimal_ops(&pswap->suboptimal_ops, &pswap->suboptimal_ops_size);
}

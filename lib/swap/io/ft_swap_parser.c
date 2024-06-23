/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_parser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 14:52:36 by abelov            #+#    #+#             */
/*   Updated: 2024/06/10 20:50:49 by abelov           ###   ########.fr       */
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

void	ft_swap_init(t_pswap *pswap)
{
	pswap->sorted = ft_tab_int_init(pswap->arg_tab_size);
	pswap->sorted = ft_copy_int_tab(pswap->stack_a, pswap->sorted,
			0, pswap->arg_tab_size - 1);
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
	pswap->operations = ft_empty_string(1);
	pswap->ops = NULL;
	init_swap_ops(&pswap->swap_ops, &pswap->swap_ops_size);
	init_suboptimal_ops(&pswap->suboptimal_ops, &pswap->suboptimal_ops_size);
}

int	*get_argtab(int arg_tab_size, char **argv, int i, int j)
{
	int		k;
	int		*tab;
	char	**argtab;

	tab = ft_tab_int_init(arg_tab_size);
	while (argv[i] && tab)
	{
		k = 0;
		if (argv[i])
		{
			argtab = ft_split(argv[i], ' ');
			if (argtab)
			{
				while (argtab[k])
					tab[j++] = ft_atoi(argtab[k++]);
				i++;
				ft_tab_free((void **) argtab);
			}
		}
	}
	return (tab);
}

int	ft_swap_do_parse(int argc, char **argv, t_pswap *pswap)
{
	int	i;
	int	count;

	pswap->arg_tab_size = 0;
	pswap->stack_a_size = 0;
	pswap->stack_b_size = 0;
	i = ft_swap_chkdbg(pswap, argc, argv) - 1;
	while (++i < argc)
	{
		count = ft_swap_count_arg_nbrs(argv[i]);
		if (count != -1)
			pswap->arg_tab_size += count;
		else
			pswap->arg_tab_size = -1;
		if (pswap->arg_tab_size == -1)
			return (-2);
	}
	i = ft_swap_chkdbg(pswap, argc, argv);
	pswap->stack_a = get_argtab(pswap->arg_tab_size, argv, i, 0);
	if (pswap->stack_a)
		pswap->stack_b = ft_tab_int_init(pswap->arg_tab_size);
	if (ft_swap_check_dup(pswap->stack_a, pswap->arg_tab_size) == -1)
		return (-1);
	ft_swap_init(pswap);
	return (0);
}

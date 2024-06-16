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

#include "libswap.h"

void	ft_swap_init(t_pswap *pswap)
{
	pswap->sorted = ft_tab_int_init(pswap->arg_tab_size);
	pswap->sorted = ft_copy_int_tab(pswap->stack_a, pswap->sorted, 0, pswap->arg_tab_size - 1);
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
}

int *get_argtab(int arg_tab_size, char **argv, int i, int j)
{
	int *tab;
	char **argtab;
	int k;

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

int ft_swap_do_parse(int argc, char **argv, t_pswap *pswap)
{
	int i;
	int count;

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

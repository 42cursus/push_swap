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

#include "psortlib.h"

void	ft_init_pswap(t_pswap *pswap)
{
	pswap->sorted = ft_init_int_tab(pswap->arg_tab_size);
	pswap->sorted = ft_copy_int_tab(pswap->stack_a, pswap->sorted, 0, pswap->arg_tab_size - 1);
	pswap->sorted = ft_sort_int_tab(pswap->sorted, pswap->arg_tab_size);
	pswap->sorted_min_nb = pswap->sorted[0];
	pswap->sorted_max_nb = pswap->sorted[pswap->arg_tab_size - 1];
	pswap->col_a_size = pswap->arg_tab_size;
	pswap->col_b_size = 0;
	if (pswap->stack_a)
		pswap->pibon_a = pswap->stack_a[pswap->arg_tab_size - 1];
	pswap->pibon_tab = ft_init_int_tab(1);
	pswap->pibon_tab_size = 1;
	*pswap->pibon_tab = pswap->sorted_min_nb;
	pswap->pushed_pibon = 0;
	pswap->top_in_a = ft_get_top_in_stack(pswap, 'a');
	pswap->top_in_b = ft_get_top_in_stack(pswap, 'b');
	pswap->operations = ft_empty_string(1);
}

int *get_argtab(int arg_tab_size, char **argv, int i, int j)
{
	int *tab;
	char **argtab;
	int k;

	tab = ft_init_int_tab(arg_tab_size);
	while (argv[i] && tab)
	{
		k = 0;
		if (argv[i])
		{
			argtab = ft_split(argv[i], ' ');
			if (argtab)
			{
				while (argtab[k])
				{
					tab[j] = ft_atoi(argtab[k]);
					k++;
					j++;
				}
				i++;
				ft_tabdel(argtab);
			}
		}
	}
	return (tab);
}

int ft_swap_parser(int argc, char **argv, t_pswap *pswap)
{
	int i;
	int count;

	pswap->arg_tab_size = 0;
	pswap->col_a_size = 0;
	pswap->col_b_size = 0;
	i = check_debug(pswap, argv, argc) - 1;
	while (++i < argc)
	{
		count = ft_count_arg_nbrs(argv[i]);
		if (count != -1)
			pswap->arg_tab_size = pswap->arg_tab_size + count;
		else
			pswap->arg_tab_size = -1;
		if (pswap->arg_tab_size == -1)
			return (-2);
	}
	i = check_debug(pswap, argv, argc);
	pswap->stack_a = get_argtab(pswap->arg_tab_size, argv, i, 0);
	if (pswap->stack_a)
		pswap->stack_b = ft_init_int_tab(pswap->arg_tab_size);
	if (ft_check_dup(pswap->stack_a, pswap->arg_tab_size) == -1)
		return (-1);
	ft_init_pswap(pswap);
	return (0);
}

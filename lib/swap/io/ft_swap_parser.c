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
	pswap->arg_tab = get_argtab(pswap->arg_tab_size, argv, i, 0);
	if (ft_swap_check_dup(pswap->arg_tab, pswap->arg_tab_size) == -1)
		return (-1);
	ft_swap_init(pswap);
	return (0);
}

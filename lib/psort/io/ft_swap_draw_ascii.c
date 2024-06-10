/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_draw_ascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:41:26 by abelov            #+#    #+#             */
/*   Updated: 2024/06/10 15:41:27 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pswap.h>

#define INT_MIN_LEN 11

int is_pibon(const int *pibons_b, int pibon_tab_size, int num)
{
	int iter;

	iter = -1;
	while (++iter < pibon_tab_size)
		if (pibons_b[iter] == num)
			return (1);
	return (-1);
}

int column_a(t_pswap *pswap, int idx)
{
	int		nblen;
	char	*fmt;
	char	*const buf = (char[INT_MIN_LEN + 1]){' '};

	nblen = ft_nblen(pswap->column_a[idx]);
	if ((pswap->pibon_a == pswap->column_a[idx]) && (pswap->top_in_a <= idx))
		fmt = "|     * %d%s";
	else
		fmt = "|       %d%s";
	buf[INT_MIN_LEN + 1 - nblen] = '\0';
	ft_printf(fmt, pswap->column_a[idx], buf);
	return idx;
}

int column_b(t_pswap *pswap, int idx)
{
	char	*fmt;
	int		nblen;
	int		b_is_pibon;
	char	*const buf = (char[INT_MIN_LEN + 1]){' '};

	nblen = ft_nblen(pswap->column_a[idx]);
	b_is_pibon = is_pibon(pswap->pibon_tab, pswap->pibon_tab_size, pswap->column_b[idx]);
	if ((b_is_pibon == 1) && (pswap->top_in_b <= idx))
		fmt = "|     * %d%s";
	else
		fmt = "|       %d%s";
	buf[INT_MIN_LEN + 1 - nblen] = '\0';
	ft_printf(fmt, pswap->column_a[idx], buf);
	ft_putstr_eol("|","\n");
	return idx;
}

void ft_swap_draw_ascii(t_pswap *pswap)
{
	int uter;
	int iter;

	iter = -1;
	if (pswap->debug == 1)
	{
		ft_putendl_fd(" __________________ __________________ ", STDOUT_FILENO);
		ft_putendl_fd("|       a          |       b          |", STDOUT_FILENO);
		ft_putendl_fd("|‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾|‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾‾|", STDOUT_FILENO);
		while (iter + 1 < pswap->arg_tab_size)
		{
			uter = column_a(pswap, iter + 1);
			iter = column_b(pswap, uter);
		}
		ft_putendl_fd("|__________________|__________________|\n", STDOUT_FILENO);
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 22:23:32 by abelov            #+#    #+#             */
/*   Updated: 2024/06/09 22:23:32 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pswap.h>
#include <psortlib.h>

int	ft_get_ops(t_pswap *pswap);

int		check_order_stack(t_pswap *pswap);


int main(int argc, char **argv)
{
	int		error_code;
	t_pswap	*pswap;
	char 	*str;

	if (argc <= 1)
		exit(EXIT_SUCCESS);
	pswap = (t_pswap *) malloc(sizeof(t_pswap));
	if (pswap == NULL)
		return (-1);
	error_code = ft_swap_parser(argc, argv, pswap);
	if ((error_code == -1) || (error_code == -2))
	{
		error_code = ft_error(pswap, error_code);
		return (error_code);
	}
	ft_swap_draw_ascii(pswap);
	if (ft_get_ops(pswap) == -1)
		return (ft_error(pswap, -3));
	str = "KO";
	if ((check_order_stack(pswap) == 0) && (pswap->arg_tab_size == pswap->col_a_size))
		str = "OK";
	ft_putstr_eol(str,"\n");
	free(pswap);
	return (EXIT_SUCCESS);
}

int		check_order_stack(t_pswap *pswap)
{
	int		i;

	i = pswap->top_in_a - 1;
	while (++i < pswap->arg_tab_size)
		if (pswap->stack_a[i] != pswap->sorted[i])
			return (-1);
	return (0);
}
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

#include "pswap.h"

int	main(int argc, char **argv)
{
	int		error_code;
	t_pswap	*pswap;
	char	*str;

	if (argc <= 1)
		exit(EXIT_SUCCESS);
	pswap = (t_pswap *) malloc(sizeof(t_pswap));
	if (pswap == NULL)
		return (-1);
	error_code = ft_swap_do_parse(argc, argv, pswap);
	if ((error_code == -1) || (error_code == -2))
	{
		error_code = ft_swap_error(pswap, error_code);
		return (error_code);
	}
	ft_swap_draw_ascii(pswap);
	if (ft_get_ops(pswap) == -1)
		return (ft_swap_error(pswap, -3));
	str = "KO";
	if ((ft_swap_is_sorted(pswap) == 0)
		&& (pswap->arg_tab_size == pswap->stack_a_size))
		str = "OK";
	ft_putstr_eol(str, "\n");
	free(pswap);
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 22:19:07 by abelov            #+#    #+#             */
/*   Updated: 2024/06/09 22:19:07 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pswap.h>
#include <psortlib.h>

int	main(int argc, char **argv)
{
	int		error_code;
	t_pswap	*pswap;

	if (argc <= 1)
		exit(EXIT_SUCCESS);
	pswap = (t_pswap *) malloc(sizeof(t_pswap));
	if (pswap == NULL)
		return (-1);
	error_code = ft_swap_parser(argc, argv, pswap);
	if ((error_code == -1) || (error_code == -2))
		return (ft_error(pswap, error_code));
	ft_swap_draw_ascii(pswap);
	ft_putstr(pswap->operations);
	free(pswap);
	return (EXIT_SUCCESS);
}

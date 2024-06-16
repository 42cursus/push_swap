/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_chkdbg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:53:11 by abelov            #+#    #+#             */
/*   Updated: 2024/06/15 16:29:50 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

int ft_swap_chkdbg(t_pswap *pswap, int argc, char **argv)
{
	int ret_val;

	ret_val = 1;
	pswap->debug = 0;
	if ((argc > 2) && (ft_strcmp(argv[1], "-d") == 0))
	{
		pswap->debug = 1;
		ret_val = 2;
	}
	return (ret_val);
}

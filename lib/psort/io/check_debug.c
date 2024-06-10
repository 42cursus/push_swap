/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:53:11 by abelov            #+#    #+#             */
/*   Updated: 2024/06/10 20:51:36 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pswap.h>

int check_debug(t_pswap *pswap, char **argv, int arc)
{
	if ((arc > 2) && (ft_strcmp(argv[1], "-d") == 0))
	{
		pswap->debug = 1;
		return (2);
	}
	pswap->debug = 0;
	return (1);
}

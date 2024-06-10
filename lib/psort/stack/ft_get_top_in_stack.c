/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_top_in_stack.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:29:56 by abelov            #+#    #+#             */
/*   Updated: 2024/06/10 20:29:57 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pswap.h>

int ft_get_top_in_stack(t_pswap *pswap, char stack)
{
	int retval;
	if (stack == 'a')
		retval = pswap->arg_tab_size - pswap->col_a_size;
	else
	{
		if (stack == 'b')
			retval = pswap->arg_tab_size - pswap->col_b_size;
		else
			retval = 0;
	}
	return (retval);
}

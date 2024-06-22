/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_get_top.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 20:29:56 by abelov            #+#    #+#             */
/*   Updated: 2024/06/15 20:55:15 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

int	ft_swap_get_top(t_pswap *pswap, char stack)
{
	int	ret_val;

	if (stack == 'a')
		ret_val = pswap->arg_tab_size - pswap->stack_a_size;
	else if (stack == 'b')
		ret_val = pswap->arg_tab_size - pswap->stack_b_size;
	else
		ret_val = 0;
	return (ret_val);
}

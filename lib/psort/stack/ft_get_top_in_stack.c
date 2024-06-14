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
	int	ret_val;

	if (stack == 'a')
		ret_val = pswap->arg_tab_size - pswap->col_a_size;
	else if (stack == 'b')
		ret_val = pswap->arg_tab_size - pswap->col_b_size;
	else
		ret_val = 0;
	return (ret_val);
}

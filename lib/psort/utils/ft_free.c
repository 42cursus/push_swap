/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:25:16 by abelov            #+#    #+#             */
/*   Updated: 2024/06/10 15:25:16 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pswap.h>

void ft_free(t_pswap *pswap)
{
	free(pswap->stack_a);
	free(pswap->stack_b);
	free(pswap->sorted);
	free(pswap->pibon_tab);
	free(pswap->operations);
}

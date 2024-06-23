/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:25:16 by abelov            #+#    #+#             */
/*   Updated: 2024/06/15 17:41:42 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pswap.h>

void	ft_swap_free(t_pswap *pswap)
{
	free(pswap->stack_a);
	free(pswap->stack_b);
	free(pswap->sorted);
	free(pswap->pivots_b);
	free(pswap->operations);
	ft_list_destroy(&pswap->ops, NULL);
}

void	ft_swap_destroy(t_pswap **pswap)
{
	ft_swap_free(*pswap);
	free(*pswap);
	*pswap = NULL;
}

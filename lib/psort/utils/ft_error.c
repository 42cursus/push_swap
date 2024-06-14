/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:16:25 by abelov            #+#    #+#             */
/*   Updated: 2024/06/10 15:16:26 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	ft_check_dup(int *argtab, int argnb)
{
	int i;
	int j;

	i = 0;
	while (i < argnb)
	{
		j = 0;
		while (j < argnb)
		{
			if (argtab[i] == argtab[j] && i != j)
				return (-1);
			else
				j++;
		}
		i++;
	}
	return (0);
}


int	ft_error(t_pswap *pswap, int err_code)
{
	if (err_code == -1)
	{
		free(pswap->stack_a);
		free(pswap->stack_b);
	}
	else if (err_code == -3)
		ft_free(pswap);
	free(pswap);
	ft_putendl_fd("Error", 2);
	return -1;
}



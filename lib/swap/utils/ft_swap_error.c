/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:16:25 by abelov            #+#    #+#             */
/*   Updated: 2024/06/15 17:41:21 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

int	ft_swap_check_dup(const int *argtab, int argnb)
{
	int	i;
	int	j;

	i = -1;
	while (++i < argnb)
	{
		j = -1;
		while (++j < argnb)
			if (argtab[i] == argtab[j] && i != j)
				return (-1);
	}
	return (0);
}

int	ft_swap_validate_input(char *nb)
{
	int			i;
	long long	n;
	int			nbr_len;
	int			ret_val;

	i = 0;
	nbr_len = 0;
	ret_val = 0;
	if ((nb[i] == '+' || nb[i] == '-') && ft_isdigit(nb[i + 1]) == 1)
		i++;
	while (nb[i] == '0')
		i++;
	while (ft_isdigit(nb[i + nbr_len]) != 0)
		nbr_len++;
	if (ft_isdigit(nb[i + nbr_len]) == 0 && nb[i + nbr_len] != '\0')
		ret_val = -1;
	else
	{
		n = ft_strtol(nb, NULL, 0);
		if (n < INT_MIN || n > INT_MAX || nbr_len > 10)
			ret_val = -1;
	}
	return (ret_val);
}

int	ft_swap_error(t_pswap *pswap, int err_code)
{
	if (err_code == -1)
		;
	else if (err_code == -2)
		free(pswap->arg_tab);
	else if (err_code == -3)
		ft_swap_free(pswap);
	free(pswap);
	ft_putendl_fd("Error", 2);
	return (-1);
}

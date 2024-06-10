/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_arg_nbrs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:39:58 by abelov            #+#    #+#             */
/*   Updated: 2024/06/10 20:47:22 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int		check_atoi(char *nb)
{
	int			i;
	long long	n;
	int			nbr_len;

	i = 0;
	nbr_len = 0;
	if ((nb[i] == '+' || nb[i] == '-') && ft_isdigit(nb[i + 1]) == 1)
		i++;
	while (nb[i] == '0')
		i++;
	while (ft_isdigit(nb[i + nbr_len]) != 0)
		nbr_len++;
	if (ft_isdigit(nb[i + nbr_len]) == 0 && nb[i + nbr_len] != '\0')
		return (-1);
	n = ft_strtol(nb, NULL, 0);
	if (n < INT_MIN || n > INT_MAX || nbr_len > 10)
		return (-1);
	return (0);
}

int	ft_count_arg_nbrs(char *argv)
{
	char **str_tab;
	int i;
	int j;

	str_tab = ft_split(argv, ' ');
	i = 0;
	j = 0;
	while (str_tab[i])
	{
		if (check_atoi(str_tab[i]) == -1)
		{
			ft_tabdel(str_tab);
			return (-1);
		}
		j++;
		i++;
	}
	ft_tabdel(str_tab);
	if (j == 0)
		j = -1;
	return (j);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_count_arg_nbrs.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:39:58 by abelov            #+#    #+#             */
/*   Updated: 2024/06/15 16:28:52 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

int	ft_swap_count_arg_nbrs(char *argn)
{
	char	**str_tab;
	int		i;
	int		j;
	int		ret_val;

	i = -1;
	j = 0;
	ret_val = -1;
	str_tab = ft_split(argn, ' ');
	while (str_tab[++i] && ++j)
	{
		if (ft_swap_validate_input(str_tab[i]) == -1)
		{
			j = 0;
			break ;
		}
	}
	ft_tab_str_free(str_tab);
	if (j != 0)
		ret_val = j;
	return (ret_val);
}

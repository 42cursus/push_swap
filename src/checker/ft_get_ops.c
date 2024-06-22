/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_ops.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 23:48:05 by abelov            #+#    #+#             */
/*   Updated: 2024/06/10 23:48:05 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

bool ft_swap_validate_op(char *line)
{
	return ft_strcmp(line, "sa\n") == 0 || ft_strcmp(line, "sb\n") == 0
			   || ft_strcmp(line, "ss\n") == 0 || ft_strcmp(line, "pa\n") == 0
			   || ft_strcmp(line, "pb\n") == 0 || ft_strcmp(line, "ra\n") == 0
			   || ft_strcmp(line, "rb\n") == 0 || ft_strcmp(line, "rr\n") == 0
			   || ft_strcmp(line, "rra\n") == 0 || ft_strcmp(line, "rrb\n") == 0
			   || ft_strcmp(line, "rrr\n") == 0;
}

int ft_get_ops(t_pswap *pswap)
{
	char	*line;
	int		i;
	int		ret_val;

	i = 0;
	ret_val = 0;
	while (i != -1 && (ft_getline(0, &line) == 1))
	{
		i++;
		if (ft_swap_validate_op(line))
			ft_swap_apply_op(pswap, *(int *) ft_strtok(line, "\n"));
		else
			i = -1;
		free(line);
		line = NULL;
	}
	if (i == -1)
		ret_val = -1;
	return (ret_val);
}

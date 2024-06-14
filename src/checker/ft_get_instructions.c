/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_instructions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 23:48:05 by abelov            #+#    #+#             */
/*   Updated: 2024/06/10 23:48:05 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pswap.h>

void	swap_operations(t_pswap *pswap, char *instruction);
void	push_operations(t_pswap *pswap, char *instruction);
void	rotate_operations(t_pswap *pswap, char *instruction);
void	reverse_operations(t_pswap *pswap, char *instruction);

int	ft_get_ops(t_pswap *env)
{
	char	*line;
	int		i;
	int		out_gnl;

	i = 0;
	out_gnl = ft_getline(0, &line);
	while (i != -1 && (out_gnl == 1))
	{
		i++;
		if (ft_strcmp(line, "sa\n") == 0 || ft_strcmp(line, "sb\n") == 0 || ft_strcmp(line, "ss\n") == 0)
			swap_operations(env, line);
		else if (ft_strcmp(line, "pa\n") == 0 || ft_strcmp(line, "pb\n") == 0)
			push_operations(env, line);
		else if (ft_strcmp(line, "ra\n") == 0 || ft_strcmp(line, "rb\n") == 0 || ft_strcmp(line, "rr\n") == 0)
			rotate_operations(env, line);
		else if (ft_strcmp(line, "rra\n") == 0 || ft_strcmp(line, "rrb\n") == 0 || ft_strcmp(line, "rrr\n") == 0)
			reverse_operations(env, line);
		else
			i = -1;
		free(line);
		line = NULL;
		out_gnl = ft_getline(0, &line);
	}
	return (i != -1 && out_gnl != -1 ? 0 : -1);
}

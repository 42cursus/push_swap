/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimization.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 18:21:10 by abelov            #+#    #+#             */
/*   Updated: 2024/06/14 18:21:10 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	delete(t_pswap *pswap, char *operations)
{
	char	*tmp;
	size_t	index;

	while (ft_strstr(pswap->operations, operations) != NULL)
	{
		index = ft_strstr(pswap->operations, operations) - pswap->operations;
		tmp = ft_empty_string(ft_strlen(pswap->operations) - ft_strlen(operations));
		tmp = ft_strncpy(tmp, pswap->operations, index);
		tmp = ft_strcat(tmp, pswap->operations + index + ft_strlen(operations));
		free(pswap->operations);
		pswap->operations = tmp;
	}
}

void	delete_operations(t_pswap *pswap)
{
	delete(pswap, "\npa\npb");
	delete(pswap, "\npb\npa");
	delete(pswap, "\nra\nrra");
	delete(pswap, "\nrb\nrrb");
	delete(pswap, "\nrra\nra");
	delete(pswap, "\nrrb\nrb");
	delete(pswap, "\nsa\nsa");
	delete(pswap, "\nsb\nsb");
}

void	replace(t_pswap *pswap, char *long_op, char *short_op)
{
	char	*tmp;
	size_t	index;

	while (ft_strstr(pswap->operations, long_op) != NULL)
	{
		index = ft_strstr(pswap->operations, long_op) - pswap->operations;
		tmp = ft_empty_string(ft_strlen(pswap->operations) - ft_strlen(long_op)
							  + ft_strlen(short_op));
		tmp = ft_strncpy(tmp, pswap->operations, index);
		tmp = ft_strcat(tmp, short_op);
		tmp = ft_strcat(tmp, pswap->operations + index + ft_strlen(long_op));
		free(pswap->operations);
		pswap->operations = tmp;
	}
}

void	optimize(t_pswap *pswap)
{
	while (ft_strstr(pswap->operations, "\npa\npb") != NULL
		|| ft_strstr(pswap->operations, "\npb\npa") != NULL
		|| ft_strstr(pswap->operations, "\nra\nrra") != NULL
		|| ft_strstr(pswap->operations, "\nrb\nrrb") != NULL
		|| ft_strstr(pswap->operations, "\nrra\nra") != NULL
		|| ft_strstr(pswap->operations, "\nrrb\nrb") != NULL
		|| ft_strstr(pswap->operations, "\nsa\nsa") != NULL
		|| ft_strstr(pswap->operations, "\nsb\nsb") != NULL)
		delete_operations(pswap);
	replace(pswap, "\nsa\nsb\n", "\nss\n");
	replace(pswap, "\nsb\nsa\n", "\nss\n");
	replace(pswap, "\nrra\nrrb\n", "\nrrr\n");
	replace(pswap, "\nrrb\nrra\n", "\nrrr\n");
	replace(pswap, "\nra\nrb\n", "\nrr\n");
	replace(pswap, "\nrb\nra\n", "\nrr\n");
}

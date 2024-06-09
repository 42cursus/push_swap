/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy_inttab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 22:59:18 by abelov            #+#    #+#             */
/*   Updated: 2024/06/09 22:59:18 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	*ft_copy_inttab(int *stack, int *copy, int start, int finish)
{
	int i;

	i = 0;
	while (i < finish - start + 1)
	{
		copy[i] = stack[start + i];
		i++;
	}
	return (copy);
}

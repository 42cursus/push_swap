/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 19:37:35 by abelov            #+#    #+#             */
/*   Updated: 2024/06/10 19:37:35 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_tabdel(char **str_tab)
{
	int i;

	if (str_tab != NULL)
	{
		i = -1;
		while (str_tab[++i] != NULL)
			free(str_tab[i]);
		free(str_tab);
	}
}

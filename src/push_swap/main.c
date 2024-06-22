/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 22:19:07 by abelov            #+#    #+#             */
/*   Updated: 2024/06/09 22:19:07 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pswap.h>

int	main(int argc, char **argv)
{
	int		error_code;
	t_pswap	*pswap;

	if (argc <= 1)
		exit(EXIT_SUCCESS);
	pswap = (t_pswap *) malloc(sizeof(t_pswap));
	if (pswap == NULL)
		return (-1);
	error_code = ft_swap_do_parse(argc, argv, pswap);
	if ((error_code == -1) || (error_code == -2))
		return (ft_swap_error(pswap, error_code));
	ft_swap_draw_ascii(pswap);
	do_sort(pswap);
	optimize(pswap);
	ft_putstr(pswap->operations);
	ft_putstr("\n==\n");
	ft_list_reverse(&pswap->ops);
	ft_list_foreach_ref(pswap->ops, (void (*)(void *, void *)) ft_putstr_eol, "\n");
	free(pswap);
	return (EXIT_SUCCESS);
}

void	do_sort(t_pswap *pswap)
{
	if (ft_swap_is_sorted(pswap) == 0 && pswap->top_a == 0)
		return ;
	else if (ft_swap_is_almost_sorted(pswap) == 1)
		sort_almost_sorted(pswap);
	else
	{
		if (pswap->arg_tab_size <= 3)
			sort_few_numbers(pswap);
		else
			ft_swap_sort_random(pswap);
	}
}

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
	void	(*foreach_fun)(void *, void *);

	if (argc <= 1)
		exit(EXIT_SUCCESS);
	pswap = (t_pswap *) malloc(sizeof(t_pswap));
	if (pswap == NULL)
		return (-1);
	error_code = ft_swap_do_parse(argc, argv, pswap);
	if (error_code)
		return (ft_swap_error(pswap, error_code));
	ft_swap_draw_ascii(pswap);
	do_sort(pswap);
	optimize(pswap, 0);
	ft_list_reverse(&pswap->ops);
	foreach_fun = (void (*)(void *, void *)) ft_putstr_eol;
	ft_list_foreach_ref(pswap->ops, foreach_fun, "\n");
	ft_swap_destroy(&pswap);
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
			ft_swap_qsort(pswap);
	}
}

void	ft_swap_qsort(t_pswap *pswap)
{
	int	pivot_p;
	int	top_in_a;

	while (pswap->stack_a_size > 1 && ft_swap_is_sorted(pswap) == -1)
	{
		pswap->pushed_pivot = 0;
		top_in_a = ft_swap_get_top(pswap, 'a');
		pivot_p = ft_swap_get_pivot(pswap, 'a',
				top_in_a, pswap->arg_tab_size - 1);
		ft_swap_sort_first_push(pswap, pivot_p);
		ft_check_few_in_a(pswap);
	}
	while (pswap->pivots_b_tab_size > 0
		&& pswap->pivots_b[0] >= pswap->stack_a[pswap->top_a])
		ft_swap_remove_pivot_b(pswap);
	top_in_a = ft_swap_get_top(pswap, 'a');
	pswap->pivot_a = pswap->stack_a[top_in_a];
	while (!(ft_swap_is_sorted(pswap) == 0
			&& pswap->stack_a_size == pswap->arg_tab_size))
		ft_swap_push_back(pswap);
}

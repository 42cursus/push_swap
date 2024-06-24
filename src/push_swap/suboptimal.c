/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   suboptimal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:46:26 by abelov            #+#    #+#             */
/*   Updated: 2024/06/24 15:46:26 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pswap.h"

void	ft_swap_reset(t_pswap *p_pswap)
{
	int	*tmp;

	tmp = p_pswap->arg_tab;
	p_pswap->arg_tab = (void *) malloc(1);
	ft_swap_free(p_pswap);
	p_pswap->arg_tab = tmp;
	ft_swap_init(p_pswap);
}

void	ft_swap_do_it_again(t_pswap *p_pswap, int attempts)
{
	int			i;

	if (attempts < 6)
	{
		i = -1;
		attempts++;
		ft_swap_reset(p_pswap);
		while (++i < attempts)
			ft_swap_do_op(p_pswap, ra);
	}
	else if (attempts > 5)
	{
		i = 4;
		attempts++;
		ft_swap_reset(p_pswap);
		while (++i < (attempts - 5))
			ft_swap_do_op(p_pswap, rra);
	}
	else
		return ;
	do_sort(p_pswap);
	optimize(p_pswap, attempts);
}

void	ft_swap_do_replace(t_pswap *pswap, const char *op1,
							const char *op2, const char *short_op)
{
	t_list				*to_find;
	t_list				*to_replace_with;
	t_list_fun *const	lst_fun = &(t_list_fun){
		.cmp_fun = (t_cmp_fun) ft_strcmp,
		.del_fun = NULL,
		.dup_fun = NULL
	};

	to_find = ft_list_push_strs(2, (const char *[2]){op1, op2});
	to_replace_with = ft_list_push_strs(1, (const char *[1]){short_op});
	ft_list_replace_sublist(&pswap->ops, to_find, to_replace_with, lst_fun);
	ft_list_destroy(&to_replace_with, NULL);
	ft_list_destroy(&to_find, NULL);
}

void	ft_swap_replace(t_pswap *pswap)
{
	size_t		iter;
	char *const	to_replace[][3] = {
	{"sa", "sb", "ss"},
	{"sb", "sa", "ss"},
	{"ra", "rb", "rr"},
	{"rb", "ra", "rr"},
	{"rrb", "rra", "rrr"},
	{"rra", "rrb", "rrr"}
	};

	iter = -1;
	while (++iter < sizeof(to_replace) / (sizeof(to_replace[0])))
		ft_swap_do_replace(pswap, to_replace[iter][0], to_replace[iter][1],
			to_replace[iter][2]);
}

int	ft_swap_contains_suboptimal(t_pswap *pswap)
{
	int			iter;
	int			is_found;
	t_list		*to_find;
	const char	**suboptimal_ops;

	iter = -1;
	is_found = false;
	while (++iter < pswap->suboptimal_ops_size)
	{
		suboptimal_ops = pswap->suboptimal_ops[iter];
		to_find = ft_list_push_strs(2, suboptimal_ops);
		is_found = ft_list_find_sublist(pswap->ops, to_find,
				(__compar_fn_t) ft_strcmp) != NULL;
		ft_list_destroy(&to_find, NULL);
		if (is_found == true)
			break ;
	}
	return (is_found);
}

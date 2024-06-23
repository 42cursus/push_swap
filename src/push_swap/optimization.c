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

void	delete(t_pswap *pswap, char *op1, char *op2)
{
	t_list	*to_delete;

	to_delete = ft_list_push_strs(2, (char *[2]){op1, op2});
	ft_list_remove_sublist(&pswap->ops, to_delete,
		(__compar_fn_t) ft_strcmp, NULL);
	ft_list_destroy(&to_delete, NULL);
}

void	delete_operations(t_pswap *pswap)
{
	delete(pswap, "pa", "pb");
	delete(pswap, "pb", "pa");
	delete(pswap, "ra", "rra");
	delete(pswap, "rb", "rrb");
	delete(pswap, "sa", "sa");
	delete(pswap, "sb", "sb");
	delete(pswap, "rrb", "rb");
	delete(pswap, "rra", "ra");
}

void	replace(t_pswap *pswap, char *op1, char *op2, char *short_op)
{
	t_list				*to_find;
	t_list				*to_replace_with;
	t_list_fun *const	lst_fun = &(t_list_fun){
		.cmp_fun = (t_cmp_fun) ft_strcmp,
		.del_fun = NULL,
		.dup_fun = (void *(*)(void *)) ft_strdup
	};

	to_find = ft_list_push_strs(2, (char *[2]){op1, op2});
	to_replace_with = ft_list_push_strs(1, (char *[1]){short_op});
	ft_list_replace_sublist(&pswap->ops, to_find, to_replace_with, lst_fun);
	ft_list_destroy(&to_replace_with, NULL);
	ft_list_destroy(&to_find, NULL);
}

int	contains_suboptimal(t_pswap *pswap)
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

void	optimize(t_pswap *pswap)
{
	while (contains_suboptimal(pswap))
		delete_operations(pswap);
	replace(pswap, "sa", "sb", "ss");
	replace(pswap, "sb", "sa", "ss");
	replace(pswap, "ra", "rb", "rr");
	replace(pswap, "rb", "ra", "rr");
	replace(pswap, "rrb", "rra", "rrr");
	replace(pswap, "rra", "rrb", "rrr");
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_do_op.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 23:56:54 by abelov            #+#    #+#             */
/*   Updated: 2024/06/23 00:22:20 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

void	ft_swap_do_op(t_pswap *pswap, int opcode)
{
	t_swap_op *const	to_find = &(t_swap_op){.opcode = opcode};
	t_swap_op			*op;
	t_object_arr		*object_arr;

	object_arr = &(t_object_arr){
		.base = pswap->swap_ops,
		.total_elems = pswap->swap_ops_size,
		.size = sizeof(t_swap_op)
	};
	op = ft_bsearch(to_find, object_arr, ft_swap_op_cmp);
	op->fun(pswap);
	ft_swap_draw_ascii(pswap);
	ft_list_push_front(&pswap->ops, &op->instruction);
}

int	ft_swap_op_cmp(const void *a, const void *b)
{
	const t_swap_op	*op1 = a;
	const t_swap_op	*op2 = b;

	return ((op1->opcode) - (op2->opcode));
}

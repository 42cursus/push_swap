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

void	ft_swap_do_op(t_pswap *pswap, int op)
{
	char	*tmp;

	ft_swap_apply_op(pswap, op);
	tmp = ft_strjoin(pswap->operations, (char *)&op);
	free(pswap->operations);
	pswap->operations = ft_strjoin(tmp, "\n");
	free(tmp);
	ft_list_push_front(&pswap->ops, ft_strdup((char *)&op));
}

int	ft_swap_op_cmp(const void *a, const void *b)
{
	const t_swap_op	*op1 = a;
	const t_swap_op	*op2 = b;

	return ((op1->opcode) - (op2->opcode));
}

void	ft_swap_apply_op(t_pswap *pswap, int opcode)
{
	t_swap_op *const	to_find = &(t_swap_op){.opcode = opcode};
	t_swap_op			*op;

	op = bsearch(to_find, pswap->swap_ops, pswap->swap_ops_size,
			sizeof(t_swap_op), ft_swap_op_cmp);
	op->fun(pswap);
	ft_swap_draw_ascii(pswap);
}

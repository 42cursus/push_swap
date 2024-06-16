/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 23:56:54 by abelov            #+#    #+#             */
/*   Updated: 2024/06/15 20:53:02 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libswap.h"

void	swap_operations(t_pswap *pswap, char *instruction)
{
	int swap;
	int top_a;
	int top_b;

	if (ft_strcmp(instruction, "sa\n") == 0 && pswap->stack_a_size > 1)
	{
		top_a = ft_swap_get_top(pswap, 'a');
		swap = pswap->stack_a[top_a];
		pswap->stack_a[top_a] = pswap->stack_a[top_a + 1];
		pswap->stack_a[top_a + 1] = swap;
	}
	else if (ft_strcmp(instruction, "sb\n") == 0 && pswap->stack_b_size > 1)
	{
		top_b = ft_swap_get_top(pswap, 'b');
		swap = pswap->stack_b[top_b];
		pswap->stack_b[top_b] = pswap->stack_b[top_b + 1];
		pswap->stack_b[top_b + 1] = swap;
	}
	else if (ft_strcmp(instruction, "ss\n") == 0)
	{
		swap_operations(pswap, "sa\n");
		swap_operations(pswap, "sb\n");
	}
	ft_swap_draw_ascii(pswap);
}

void	push_operations(t_pswap *pswap, char *instruction)
{
	if (ft_strcmp(instruction, "pa\n") == 0 && (pswap->stack_b_size > 0))
	{
		pswap->stack_a[ft_swap_get_top(pswap, 'a') - 1] = pswap->stack_b[ft_swap_get_top(pswap, 'b')];
		pswap->stack_b[ft_swap_get_top(pswap, 'b')] = 0;
		pswap->stack_b_size--;
		pswap->stack_a_size++;
	}
	else if (ft_strcmp(instruction, "pb\n") == 0 && (pswap->stack_a_size > 0))
	{
		pswap->stack_b[ft_swap_get_top(pswap, 'b') - 1] = pswap->stack_a[ft_swap_get_top(pswap, 'a')];
		pswap->stack_a[ft_swap_get_top(pswap, 'a')] = 0;
		pswap->stack_a_size--;
		pswap->stack_b_size++;
	}
	pswap->top_a = ft_swap_get_top(pswap, 'a');
	pswap->top_b = ft_swap_get_top(pswap, 'b');
	ft_swap_draw_ascii(pswap);
}

void	rotate_operations(t_pswap *pswap, char *instruction)
{
	int		first;
	int		topnb;

	if (ft_strcmp(instruction, "ra\n") == 0 && pswap->stack_a_size > 0)
	{
		topnb = ft_swap_get_top(pswap, 'a');
		first = pswap->stack_a[topnb];
		while (++(topnb) < pswap->arg_tab_size)
			pswap->stack_a[topnb - 1] = pswap->stack_a[topnb];
		pswap->stack_a[pswap->arg_tab_size - 1] = first;
	}
	else if (ft_strcmp(instruction, "rb\n") == 0 && pswap->stack_b_size > 0)
	{
		topnb = ft_swap_get_top(pswap, 'b');
		first = pswap->stack_b[topnb];
		while (++(topnb) < pswap->arg_tab_size)
			pswap->stack_b[topnb - 1] = pswap->stack_b[topnb];
		pswap->stack_b[pswap->arg_tab_size - 1] = first;
	}
	else if (ft_strcmp(instruction, "rr\n") == 0)
	{
		rotate_operations(pswap, "ra\n");
		rotate_operations(pswap, "rb\n");
	}
	ft_swap_draw_ascii(pswap);
}

void	reverse_operations(t_pswap *pswap, char *instruction)
{
	int i;
	int last;

	i = pswap->arg_tab_size - 1;
	if (ft_strcmp(instruction, "rra\n") == 0 && pswap->stack_a_size > 0)
	{
		last = pswap->stack_a[pswap->arg_tab_size - 1];
		while (--i + 1 > ft_swap_get_top(pswap, 'a'))
			pswap->stack_a[i + 1] = pswap->stack_a[i];
		pswap->stack_a[ft_swap_get_top(pswap, 'a')] = last;
	}
	else if (ft_strcmp(instruction, "rrb\n") == 0 && pswap->stack_b_size > 0)
	{
		last = pswap->stack_b[pswap->arg_tab_size - 1];
		while (--i + 1 > ft_swap_get_top(pswap, 'b'))
			pswap->stack_b[i + 1] = pswap->stack_b[i];
		pswap->stack_b[ft_swap_get_top(pswap, 'b')] = last;
	}
	else if (ft_strcmp(instruction, "rrr\n") == 0)
	{
		reverse_operations(pswap, "rra\n");
		reverse_operations(pswap, "rrb\n");
	}
	ft_swap_draw_ascii(pswap);
}

void	ft_swap_do_op(t_pswap *pswap, char *op)
{
	char	*tmp;

	if (ft_strcmp(op, "sa\n") == 0 || ft_strcmp(op, "sb\n") == 0 || ft_strcmp(op, "ss\n") == 0)
		swap_operations(pswap, op);
	else if (ft_strcmp(op, "pa\n") == 0 || ft_strcmp(op, "pb\n") == 0)
		push_operations(pswap, op);
	else if (ft_strcmp(op, "ra\n") == 0 || ft_strcmp(op, "rb\n") == 0 || ft_strcmp(op, "rr\n") == 0)
		rotate_operations(pswap, op);
	else if (ft_strcmp(op, "rra\n") == 0 || ft_strcmp(op, "rrb\n") == 0 || ft_strcmp(op, "rrr\n") == 0)
		reverse_operations(pswap, op);

	tmp = ft_strjoin(pswap->operations, op);
	free(pswap->operations);
	pswap->operations = tmp;
}

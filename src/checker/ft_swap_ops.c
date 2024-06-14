/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 23:56:54 by abelov            #+#    #+#             */
/*   Updated: 2024/06/10 23:56:55 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pswap.h>
#include <psortlib.h>

void	swap_operations(t_pswap *pswap, char *instruction)
{
	int swap;
	int top_a;
	int top_b;

	if (ft_strcmp(instruction, "sa\n") == 0 && pswap->col_a_size > 1)
	{
		top_a = ft_get_top_in_stack(pswap, 'a');
		swap = pswap->stack_a[top_a];
		pswap->stack_a[top_a] = pswap->stack_a[top_a + 1];
		pswap->stack_a[top_a + 1] = swap;
	}
	else if (ft_strcmp(instruction, "sb\n") == 0 && pswap->col_b_size > 1)
	{
		top_b = ft_get_top_in_stack(pswap, 'b');
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
	int top_in_a;
	int top_in_b;

	top_in_a = ft_get_top_in_stack(pswap, 'a');
	top_in_b = ft_get_top_in_stack(pswap, 'b');
	if (ft_strcmp(instruction, "pa\n") == 0 && (pswap->col_b_size > 0))
	{
		pswap->stack_a[top_in_a - 1] = pswap->stack_b[top_in_b];
		pswap->stack_b[top_in_b] = 0;
		pswap->col_b_size--;
		pswap->col_a_size++;
	}
	else if (ft_strcmp(instruction, "pb\n") == 0 && (pswap->col_a_size > 0))
	{
		pswap->stack_b[top_in_b - 1] = pswap->stack_a[top_in_a];
		pswap->stack_a[top_in_a] = 0;
		pswap->col_a_size--;
		pswap->col_b_size++;
	}
	pswap->top_in_a = top_in_a;
	pswap->top_in_b = top_in_b;
	ft_swap_draw_ascii(pswap);
}

void	rotate_operations(t_pswap *pswap, char *instruction)
{
	int		first;
	int		topnb;

	if (ft_strcmp(instruction, "ra\n") == 0 && pswap->col_a_size > 0)
	{
		topnb = ft_get_top_in_stack(pswap, 'a');
		first = pswap->stack_a[topnb];
		while (++(topnb) < pswap->arg_tab_size)
			pswap->stack_a[topnb - 1] = pswap->stack_a[topnb];
		pswap->stack_a[pswap->arg_tab_size - 1] = first;
	}
	else if (ft_strcmp(instruction, "rb\n") == 0 && pswap->col_b_size > 0)
	{
		topnb = ft_get_top_in_stack(pswap, 'b');
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
	if (ft_strcmp(instruction, "rra\n") == 0 && pswap->col_a_size > 0)
	{
		last = pswap->stack_a[pswap->arg_tab_size - 1];
		while (--i + 1 > ft_get_top_in_stack(pswap, 'a'))
			pswap->stack_a[i + 1] = pswap->stack_a[i];
		pswap->stack_a[ft_get_top_in_stack(pswap, 'a')] = last;
	}
	else if (ft_strcmp(instruction, "rrb\n") == 0 && pswap->col_b_size > 0)
	{
		last = pswap->stack_b[pswap->arg_tab_size - 1];
		while (--i + 1 > ft_get_top_in_stack(pswap, 'b'))
			pswap->stack_b[i + 1] = pswap->stack_b[i];
		pswap->stack_b[ft_get_top_in_stack(pswap, 'b')] = last;
	}
	else if (ft_strcmp(instruction, "rrr\n") == 0)
	{
		reverse_operations(pswap, "rra\n");
		reverse_operations(pswap, "rrb\n");
	}
	ft_swap_draw_ascii(pswap);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pswap.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 13:54:00 by abelov            #+#    #+#             */
/*   Updated: 2024/06/10 13:54:01 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSWAP_H
# define PSWAP_H

# include "ft/libft.h"

typedef struct s_pswap t_pswap;
struct s_pswap
{
	int arg_tab_size;
	int sorted_min_nb;
	int sorted_max_nb;
	int *stack_a;
	int *stack_b;
	int col_a_size;
	int col_b_size;
	int top_in_a;
	int top_in_b;
	int pibon_a;
	int *pibon_tab;
	int pibon_b;
	int pushed_pibon;
	int pibon_tab_size;
	int *sorted;
	int debug;
	char *operations;
};

#endif //PSWAP_H

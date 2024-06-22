/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libswap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 22:40:05 by abelov            #+#    #+#             */
/*   Updated: 2024/06/15 21:19:42 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBSWAP_H
# define LIBSWAP_H
# include "libft.h"
# define INT_MIN_LEN 11

/**
 * Mapping Sparse Lookup Table to Function Pointer Array in C
 * https://stackoverflow.com/questions/17867391
 */

typedef struct s_pswap t_pswap;
typedef void (*t_swap_fun)(t_pswap *);
typedef struct s_swap_operation
{
	union
	{
		int		opcode;
		char	*instruction;
	};
	t_swap_fun	fun;
}	t_swap_op;

# define FT_SWAP_OP_SA 0x6173 /* *(int *)"sa" */
# define FT_SWAP_OP_SB 0x6273
# define FT_SWAP_OP_SS 0x7373
# define FT_SWAP_OP_PA 0x6170
# define FT_SWAP_OP_PB 0x6270
# define FT_SWAP_OP_RA 0x6172
# define FT_SWAP_OP_RB 0x6272
# define FT_SWAP_OP_RR 0x7272
# define FT_SWAP_OP_RRA 0x617272
# define FT_SWAP_OP_RRB 0x627272
# define FT_SWAP_OP_RRR 0x727272

typedef enum command
{
	sa = FT_SWAP_OP_SA,
	sb = FT_SWAP_OP_SB,
	ss = FT_SWAP_OP_SS,
	pa = FT_SWAP_OP_PA,
	pb = FT_SWAP_OP_PB,
	ra = FT_SWAP_OP_RA,
	rb = FT_SWAP_OP_RB,
	rr = FT_SWAP_OP_RR,
	rra = FT_SWAP_OP_RRA,
	rrb = FT_SWAP_OP_RRB,
	rrr = FT_SWAP_OP_RRR
}			t_command;

struct s_pswap
{
	int			arg_tab_size;
	int			sorted_min_nbr;
	int			sorted_max_nbr;
	int			*stack_a;
	int			*stack_b;
	int			stack_a_size;
	int			stack_b_size;
	int			top_a;
	int			top_b;
	int			pivot_a;
	int			pivot_b;
	int			*pivots_b;
	int			pivots_b_tab_size;
	int			pushed_pivot;
	int			*sorted;
	int			debug;
	char		*operations;
	t_list		*ops;
	t_swap_op	*swap_ops;
	int			swap_ops_size;
};

void	ft_swap_apply_op(t_pswap *pswap, int op);
void	ft_swap_do_op(t_pswap *pswap, int op);
int		ft_swap_op_cmp(const void *a, const void *b);
void	ft_swap_do_sa_op(t_pswap *pswap);
void	ft_swap_do_sb_op(t_pswap *pswap);
void	ft_swap_do_ss_op(t_pswap *pswap);
void	ft_swap_do_pa_op(t_pswap *pswap);
void	ft_swap_do_pb_op(t_pswap *pswap);
void	ft_swap_do_ra_op(t_pswap *pswap);
void	ft_swap_do_rb_op(t_pswap *pswap);
void	ft_swap_do_rr_op(t_pswap *pswap);
void	ft_swap_do_rra_op(t_pswap *pswap);
void	ft_swap_do_rrb_op(t_pswap *pswap);
void	ft_swap_do_rrr_op(t_pswap *pswap);

int		ft_swap_count_arg_nbrs(char *argn);
int		ft_swap_do_parse(int argc, char **argv, t_pswap *pswap);
int		ft_swap_chkdbg(t_pswap *pswap, int argc, char **argv);
void	ft_swap_draw_ascii(t_pswap *pswap);
int		ft_swap_get_top(t_pswap *pswap, char stack);
int		ft_swap_is_sorted(t_pswap *pswap);
int		ft_swap_is_almost_sorted(t_pswap *pswap);

void	ft_swap_chktop_both_stacks(t_pswap *pswap);

void	ft_swap_lteq_pivot(t_pswap *pswap, int pivot);
int		ft_swap_chklteq_pivot(int const *tab, int top, int tab_len, int pivot);
int		ft_swap_chkgt_pivot(int const *tab, int first, int last, int pibon);
int		ft_swap_validate_input(char *nb);

void	ft_swap_add_pivot_b(t_pswap *pswap, int pivot);
void	ft_swap_remove_pivot_b(t_pswap *pswap);
int		ft_swap_get_pivot(t_pswap *pswap, char stack_name, int first, int last);
int		ft_swap_get_pivot_index(t_pswap *pswap, char stack);
int		ft_swap_get_curr_pivot_b(t_pswap *pswap);
int		ft_swap_pivot_a(t_pswap *pswap);
void	ft_swap_rot_pivot_min(t_pswap *pswap, int pivot, int rotations);
void	ft_swap_rotate_pivot_b(t_pswap *pswap);
void	ft_swap_push_back_in_order(t_pswap *pswap);

void	ft_swap_lt_four_nbrs_stack_b(t_pswap *pswap);

void	ft_swap_sort2_a(t_pswap *pswap);
void	ft_swap_sort3_a(t_pswap *pswap);
void	ft_swap_sort2_b(t_pswap *pswap);
void	ft_swap_sort3_b(t_pswap *pswap);

int		ft_swap_push_to(t_pswap *pswap);
int		ft_swap_push_back(t_pswap *pswap);

void	ft_swap_push_a_to_b(t_pswap *pswap);


void	ft_swap_sort_b_to_a(t_pswap *pswap, int pivot);
int		ft_swap_sort_a_to_b(t_pswap *pswap, int pivot, int count_rotations);

void	ft_swap_free(t_pswap *pswap);
void	ft_swap_destroy(t_pswap **pswap);
int		ft_swap_error(t_pswap *pswap, int err_code);
int		ft_swap_check_dup(const int *argtab, int argnb);

#endif //LIBSWAP_H

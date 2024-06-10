/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   psort.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 22:40:05 by abelov            #+#    #+#             */
/*   Updated: 2024/06/09 22:40:06 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PSORTLIB_H
# define PSORTLIB_H
# include "utils.h"

int		ft_count_arg_nbrs(char *argn);
int		ft_swap_parser(int argc, char **argv, t_pswap *pswap);
int		check_debug(t_pswap *pswap, char **argv, int arc);
void	draw_ascii(t_pswap *pswap);
int		ft_get_top_in_stack(t_pswap *pswap, char stack);
#endif //PSORTLIB_H

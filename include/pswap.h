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

# include "libft.h"
# include "libswap.h"

void	do_sort(t_pswap *pswap);
void	optimize(t_pswap *pswap);
int		ft_get_ops(t_pswap *pswap);
void	ft_check_few_in_a(t_pswap *pswap);
void	sort_almost_sorted(t_pswap *pswap);
void	sort_from_a_to_b_first_push(t_pswap *pswap, int pivot);
void	sort_few_numbers(t_pswap *pswap);
void	ft_swap_qsort(t_pswap *pswap);
void	ft_swap_sort_first_push(t_pswap *pswap, int pivot);

#endif //PSWAP_H

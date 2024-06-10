/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelov <abelov@student.42london.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 15:30:37 by abelov            #+#    #+#             */
/*   Updated: 2024/06/10 15:30:37 by abelov           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <pswap.h>
# include <unistd.h>
# include <stdlib.h>

void	ft_free(t_pswap *pswap);
int		ft_error(t_pswap *pswap, int err_code);
void	ft_tabdel(char **str_tab);
int		ft_check_dup(int *argtab, int argnb);
#endif //UTILS_H

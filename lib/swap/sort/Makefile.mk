# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/14 17:40:02 by abelov            #+#    #+#              #
#    Updated: 2024/06/15 20:54:47 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES	= ft_swap_a_to_b.c \
            ft_swap_b_to_a.c \
            ft_swap_check.c \
            ft_swap_get_pivot.c \
            ft_swap_pivot_ops.c \
            ft_swap_push_back.c \
            ft_swap_push_to.c \
            ft_swap_sort.c

SRCS    += $(FILES:%.c=$(dir $(lastword $(MAKEFILE_LIST)))%.c)

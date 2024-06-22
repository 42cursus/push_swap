# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/09 23:00:16 by abelov            #+#    #+#              #
#    Updated: 2024/06/15 20:55:22 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES	= ft_swap_do_op.c \
            ft_swap_do_push_op.c \
            ft_swap_do_rev_rot_op.c \
            ft_swap_do_rotate_op.c \
            ft_swap_do_swap_op.c \
            ft_swap_get_top.c

SRCS    += $(FILES:%.c=$(dir $(lastword $(MAKEFILE_LIST)))%.c)

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/09 23:00:16 by abelov            #+#    #+#              #
#    Updated: 2024/06/10 15:34:33 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES	= check_debug.c \
			ft_count_arg_nbrs.c \
			ft_swap_draw_ascii.c \
			ft_swap_parser.c

SRCS    += $(FILES:%.c=$(dir $(lastword $(MAKEFILE_LIST)))%.c)

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/09 23:00:16 by abelov            #+#    #+#              #
#    Updated: 2024/06/09 23:00:16 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FILES	= ft_get_top_in_stack.c

SRCS    += $(FILES:%.c=$(dir $(lastword $(MAKEFILE_LIST)))%.c)

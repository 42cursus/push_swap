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

FILES	= ft_error.c \
			ft_free.c \
			ft_tabdel.c

SRCS    += $(FILES:%.c=$(dir $(lastword $(MAKEFILE_LIST)))%.c)

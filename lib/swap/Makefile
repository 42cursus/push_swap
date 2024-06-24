# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/09 22:25:15 by abelov            #+#    #+#              #
#    Updated: 2024/06/09 22:25:16 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= libswap.a
TOPDIR			= $(PWD)
CC				:= cc
CFLAGS			:= -Wall -Wextra -Werror -Wimplicit
INCLUDE_FLAGS	:= -I. -I./include -I../../include -I../../include/ft -I/usr/include
DEBUG_FLAGS		:= -g3 -gdwarf-3 -ffile-prefix-map=$(TOPDIR)=./staging/

CTAGS			:= ctags
LIB_COMMAND		:= ar rcs
RM				:= /bin/rm

SRCS	 		:=
DIRS			:= utils io sort stack

include $(addsuffix /Makefile.mk,$(DIRS))

BUILD_DIR		= build
OBJS			= $(SRCS:%.c=%.o)
BUILD_OBJS		= $(SRCS:%.c=$(BUILD_DIR)/%.o)
ASM_FILES		= $(SRCS:.c=.s)

all: $(NAME)
	nm --defined-only -f sysv $(NAME) | grep -v 'wm.'

$(BUILD_DIR)/%.o:	%.c
		@if [ ! -d $(@D) ]; then mkdir -pv $(@D); fi
		$(CC) $(CFLAGS) $(DEBUG_FLAGS) $(INCLUDE_FLAGS) -c $< -o $@

$(NAME): $(BUILD_OBJS)
		$(LIB_COMMAND) $(NAME) $(BUILD_OBJS)

clean:
		$(RM) -f $(OBJS) $(ASM_FILES)

fclean: clean
		$(RM) -fr $(NAME) $(BUILD_DIR) a.out

re: fclean all

norm:
		@norminette --use-gitignore

.PHONY: all

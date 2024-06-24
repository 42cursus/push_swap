# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abelov <abelov@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/09 22:25:06 by abelov            #+#    #+#              #
#    Updated: 2024/06/09 22:25:07 by abelov           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			:= .push_swap
CC				:= cc
CTAGS			:= ctags
RM				:= /bin/rm

INC_DIR			=  ./include
INCLUDE_FLAGS	:= -I. -I$(INC_DIR) -I/usr/include
OPTIMIZE_FLAGS	:= -O0
DEBUG_FLAGS		:= -g3 -gdwarf-3
MANDATORY_FLAGS	:= -Wall -Wextra -Werror
CFLAGS			= $(MANDATORY_FLAGS) $(DEBUG_FLAGS) $(OPTIMIZE_FLAGS) $(INCLUDE_FLAGS)

LIBFT_PATH		=  ./lib/ft
LIBFT			=  $(LIBFT_PATH)/libft.a

LIBSWAP_PATH	=  ./lib/swap
LIBSWAP			=  $(LIBSWAP_PATH)/libswap.a

LIBS			:= $(LIBFT) $(LIBSWAP)

LINK_FLAGS		:= -L$(LIBFT_PATH) -L$(LIBSWAP_PATH) -lswap  -lft

BUILD_DIR		= build
BIN_DIR			= $(BUILD_DIR)/bin
SRC_DIR			= src
OBJ_DIR			= $(BUILD_DIR)/obj

EXECS			= push_swap checker

push_swap_FS 	=  ft_push_and_swap.c \
					main.c \
					optimization.c \
					suboptimal.c
push_swap_SRCS	=  $(push_swap_FS:%.c=push_swap/%.c) # Substitution references
push_swap_OBJS	=  $(push_swap_SRCS:%.c=$(OBJ_DIR)/%.o)

checker_SRCS	=  checker/ft_get_ops.c checker/main.c
checker_OBJS	=  $(checker_SRCS:%.c=$(OBJ_DIR)/%.o)

all: 	$(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(@D)
		$(CC) $(CFLAGS) $(INCLUDE_FLAGS) -o $@ -c $<

# https://stackoverflow.com/questions/33639086/
# https://www.gnu.org/software/make/manual/make.html#Static-Pattern
# https://www.gnu.org/software/make/manual/make.html#Secondary-Expansion
.SECONDEXPANSION:
$(EXECS:%=$(BIN_DIR)/%): $(BIN_DIR)/% : $$(patsubst $(BIN_DIR)/%,$$(%_OBJS),$$@)
		@mkdir -p $(@D)
		$(CC) $(CFLAGS) $^ -o $@ $(LINK_FLAGS)

$(NAME): $(LIBS) $(EXECS:%=$(BIN_DIR)/%)
		cp -v $(EXECS:%=$(BIN_DIR)/%) ./
		@touch $@

$(LIBFT):
		@$(MAKE) -C $(LIBFT_PATH) -j8

$(LIBSWAP):
		@$(MAKE) -C $(LIBSWAP_PATH) -j8

clean:
		@$(RM) -fr $(OBJ_DIR) $(NAME)
		@$(MAKE) -C $(LIBFT_PATH) clean
		@$(MAKE) -C $(LIBSWAP_PATH) clean

fclean: clean
		@$(RM) -fr $(NAME) $(BUILD_DIR) a.out
		@$(MAKE) -C $(LIBFT_PATH) fclean
		@$(MAKE) -C $(LIBSWAP_PATH) fclean

re: fclean all

bonus: checker

norm:
		@norminette --use-gitignore
		@$(MAKE) -C $(LIBFT_PATH) norm
		@$(MAKE) -C $(LIBSWAP_PATH) norm

.PHONY: all clean test re norm

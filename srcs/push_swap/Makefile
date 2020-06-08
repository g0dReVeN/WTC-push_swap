# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jordan_macos <jordan_macos@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/28 11:41:24 by jgovend           #+#    #+#              #
#    Updated: 2018/08/26 16:35:41 by jordan_maco      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := push_swap

SRC_PATH := ./srcs

SRC := push_swap.c exec_ops.c error_h.c stack_ops.c inst_ops.c algo_ops.c

OBJ_PATH := ./objs

OBJ := $(addprefix $(OBJ_PATH)/,$(SRC:%.c=%.o))

LIB_PATH := ../../libft

LIB := libft.a

CC := gcc

FLAGS := -g -Wall -Werror -Wextra  -I ./includes

all: $(NAME)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

$(OBJ_PATH)/%.o:$(SRC_PATH)/%.c
	@$(CC) $(FLAGS) -o $@ -c $<

$(NAME): $(OBJ_PATH) $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) $(LIB_PATH)/$(LIB) -o ../../$(NAME)

clean:
	@rm -Rf $(OBJ_PATH)

fclean: clean
	@rm -Rf ../../$(NAME)

re: fclean all

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jordan_macos <jordan_macos@student.42.f    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/28 11:41:24 by jgovend           #+#    #+#              #
#    Updated: 2018/08/24 16:55:18 by jordan_maco      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

P1 := checker

P2 := push_swap

P1_PATH := ./srcs/checker

P2_PATH := ./srcs/push_swap

LIB_PATH := ./libft

all:
	@make re -C $(LIB_PATH)
	@make re -C $(P1_PATH)
	@make re -C $(P2_PATH)

clean:
	@make fclean -C $(LIB_PATH)
	@make clean -C $(P1_PATH)
	@make clean -C $(P2_PATH)

fclean: clean
	@rm -Rf $(P1)
	@rm -Rf $(P2) 

re: fclean all

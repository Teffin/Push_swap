# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hharrold <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/25 14:15:40 by hharrold          #+#    #+#              #
#    Updated: 2019/04/25 14:15:43 by hharrold         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME1 = checker

NAME2 = push_swap

SRC1 = ./check/main.c  ./push/ft_create_push_list.c ./push/ft_print_nums.c \
		./push/ft_check_valid.c \
		./push/ft_push_swap_rotate.c ./push/ft_supporting.c \
		./push/ft_sup_algorithm.c ./push/ft_print_command.c ./check/ft_take.c \
		./push/ft_check_flag.c

SRC2 = ./push/main.c ./push/ft_create_push_list.c ./push/ft_print_nums.c \
	./push/ft_check_valid.c \
	./push/ft_push_swap_rotate.c ./push/ft_supporting.c \
	./push/ft_sup_algorithm.c ./push/ft_algorithm.c \
	./push/ft_push_faster_on_a.c ./push/ft_push_faster_on_b.c \
	./push/ft_score_for_rotate.c ./push/ft_print_command.c \
	./push/ft_check_flag.c

HEAD = ./includes/

WWW = -Wall -Wextra -Werror

OBG1 = ./obj_check/*.o

OBG2 = ./obj_push/*.o

LFT = libft

all: lib $(NAME2) $(NAME1)

lib:
		@make -C $(LFT)

$(NAME1):
		@mkdir obj_check
		@gcc $(WWW) \
		-I $(HEAD) \
		-c $(SRC1)
		@mv *.o obj_check/
		@gcc $(WWW) \
		$(LFT)/libft.a \
		-I $(HEAD) $(OBG1)  -o $(NAME1)
		@echo Compiled $(NAME1)!

$(NAME2):
		@mkdir obj_push
		@gcc $(WWW) \
		-I $(HEAD) \
		-c $(SRC2)
		@mv *.o obj_push/
			@gcc $(WWW) \
		$(LFT)/libft.a \
		-I $(HEAD) $(OBG2)  -o $(NAME2)
		@echo Compiled $(NAME2)!

clean:
		@rm -rf obj_check
		@rm -rf obj_push
		@make -C $(LFT) fclean

fclean: clean
		@rm -rf $(NAME1)
		@rm -rf $(NAME2)

re: fclean all

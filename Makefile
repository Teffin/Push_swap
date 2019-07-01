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

NAME1 = push_swap

NAME2 = checker

SRC1 = ./check/main.c ./check/ft_create_push_list.c ./check/ft_print_nums.c \
	./check/ft_check_valid.c \
	./check/ft_push_swap_rotate.c ./check/ft_supporting.c

SRC2 = ./push/main.c ./push/ft_check_valid.c

HEAD = ./includes/

WWW = -Wall -Wextra -Werror

OBG1 = ./obj_check/*.o

OBG2 = ./obj_push/*.o

LFT = libft

all: $(NAME1) 

$(NAME1):
		
		@mkdir obj_check
		@make -C $(LFT) re
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

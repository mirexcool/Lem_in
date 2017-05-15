# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yyefimov <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/30 14:45:44 by yyefimov          #+#    #+#              #
#    Updated: 2017/05/11 19:23:11 by yyefimov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB = libft/libft.a

NAME = lem-in

FLAGS = -Wall -Wextra -Werror
CC = gcc

SRC =	get_next_line.c\
		funcs_1.c\
		funcs_2.c\
		funcs_3.c\
		funcs_4.c\
		func_5.c\
		get_ways.c\
		lem_in.c\
		make_ways.c\
		move_ants.c\
		way_filter.c


OBJ = $(SRC:.c=.o)

all:	$(LIB) $(NAME)

$(LIB):
			@make -C ./libft

$(NAME): $(OBJ)
		@echo Compiling LEM_IN . . . 
		@$(CC) $(CFLAGS) $(OBJ) -o $(NAME) $(LIB)

%.o: %.c
		@$(CC) -c $(CFLAGS) -o $@ $<	

clean:
		@make clean -C ./libft
		@rm -f $(OBJ)	

fclean:
		@make fclean -C ./libft
		@make clean
		@rm -f $(NAME)
re:
		@make fclean
		@make all

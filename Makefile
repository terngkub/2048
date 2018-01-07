# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/06 12:18:38 by nkamolba          #+#    #+#              #
#    Updated: 2018/01/07 22:10:31 by nkamolba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = game_2048
FLAG = -Wall -Wextra -Werror -g3
LIB = -Llibft -lft -lncurses
LIBFT = libft/libft.a
HEADER = game_2048.h

FILE = main.c\
	   start_game.c\
	   print_menu.c\
	   create_map.c\
	   run_game.c\
	   print_board.c\
	   reset_stop.c\
	   check_win.c\
	   check_lost.c\
	   clean_map.c\
	   add_random.c\
	   movement.c\
	   slide_board.c\
	   do_direction.c\
	   log_two.c\
	   clean_window.c\
	   copy_board.c\
	   compare_board.c

FILE_O = $(FILE:%.c=%.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C libft

$(NAME): $(FILE_O) $(HEADER) | $(LIBFT)
	gcc $(FLAG) -o $(NAME) $(FILE_O) $(LIB)

%.o: %.c $(HEADER)
	gcc $(FLAG) -c $< -o $@

clean:
	@make clean -C libft
	rm -f $(FILE_O)

fclean: clean
	@rm -f $(LIBFT)
	@echo "libft.a fclean done"
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/06 12:18:38 by nkamolba          #+#    #+#              #
#    Updated: 2018/01/06 12:24:41 by nkamolba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = game_2048
FLAG = -Wall -Wextra -Werror
LIB = -Llibft -lft -lncurses

FILE = main.c create_map.c

FILE_O = $(FILE:%.c=%.o)

all: $(LIBFT) $(NAME)

$(LIBFT):
	@make -C libft

$(NAME): $(FILE_O) | $(LIBFT)
	gcc $(FLAG) -o $(NAME) $(FILE_O) $(LIB)

%.o: %.c
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

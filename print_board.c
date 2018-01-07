/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 14:31:31 by nkamolba          #+#    #+#             */
/*   Updated: 2018/01/07 21:17:21 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void		set_color(void)
{
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
	init_pair(6, COLOR_BLUE, COLOR_BLACK);
	init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(8, COLOR_RED, COLOR_BLACK);
	init_color(COLOR_YELLOW, 1000, 1000, 0);
	init_color(COLOR_GREEN, 500, 1000, 0);
	init_color(COLOR_CYAN, 0, 1000, 800);
	init_color(COLOR_BLUE, 0, 600, 1000);
	init_color(COLOR_MAGENTA, 600, 400, 1000);
	init_color(COLOR_RED, 1000, 500, 750);
}

static void		print_more(t_map *map)
{
	set_color();
	mvprintw(1, map->size * 10 + 3, "Score to win:");
	mvprintw(2, map->size * 10 + 7, "%d", WIN_VALUE);
	mvprintw(4, map->size * 10 + 3, "Score:");
	mvprintw(5, map->size * 10 + 7, "%d", map->score);
	mvprintw((map->size - 1) * 5 + 0, map->size * 10 + 3, "Instruction");
	mvprintw((map->size - 1) * 5 + 2, map->size * 10 + 3, "ARROW : move piece");
	mvprintw((map->size - 1) * 5 + 3, map->size * 10 + 3, "R     : replay");
	mvprintw((map->size - 1) * 5 + 4, map->size * 10 + 3, "ESC   : exit");
	refresh();
	check_win(map);
}

static void		print_block(t_map *map, WINDOW ***win, size_t i, size_t j)
{
	size_t	width;

	win[i][j] = newwin(5, 10, i * 5, j * 10);
	wattron(win[i][j], COLOR_PAIR(log_two(map->board[i][j]) % 7 + 2));
	if (map->board[i][j] != 0)
	{
		width = ft_numlen(map->board[i][j]);
		mvwprintw(win[i][j], 2, 5 - width / 2, "%d", map->board[i][j]);
	}
	box(win[i][j], 0, 0);
	wattroff(win[i][j], COLOR_PAIR(log_two(map->board[i][j]) % 7 + 2));
	wrefresh(win[i][j]);
}

static WINDOW	***create_window(size_t size)
{
	size_t	i;
	WINDOW	***win;

	win = (WINDOW ***)malloc(sizeof(WINDOW **) * size);
	i = 0;
	while (i < size)
	{
		win[i] = (WINDOW **)malloc(sizeof(WINDOW *) * size);
		i++;
	}
	return (win);
}

void			print_board(t_map *map)
{
	size_t	i;
	size_t	j;
	WINDOW	***win;

	if (!(win = create_window(map->size)))
		return ;
	print_more(map);
	i = -1;
	while (++i < map->size)
	{
		j = 0;
		while (j < map->size)
		{
			print_block(map, win, i, j);
			j++;
		}
	}
}

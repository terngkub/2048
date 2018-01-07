/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 14:31:31 by nkamolba          #+#    #+#             */
/*   Updated: 2018/01/07 17:24:51 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void set_color()
{
	init_color(COLOR_YELLOW, 1000, 1000, 0);
	init_color(COLOR_GREEN, 500, 1000, 0);
	init_color(COLOR_CYAN, 0, 1000, 800);
	init_color(COLOR_BLUE, 0, 600, 1000);
	init_color(COLOR_MAGENTA, 600, 400, 1000);
	init_color(COLOR_RED, 1000, 500, 750);
}

static void color_pair(void)
{
	init_pair(2, COLOR_WHITE, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
	init_pair(6, COLOR_BLUE, COLOR_BLACK);
	init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(8, COLOR_RED, COLOR_BLACK);
}

int			log_two(int n)
{
	int		result;

	result = 0;
	while (n >= 2)
	{
		n /= 2;
		result++;
	}
	return (result);
}

static void	print_board(t_map *map)
{
	WINDOW	*win[map->size][map->size];
	size_t	i;
	size_t	j;
	size_t	width;

	color_pair();
	set_color();
	i = 0;
	while (i < map->size)
	{
		j = 0;
		while (j < map->size)
		{
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
			j++;
		}
		i++;
	}
	mvprintw(1, map->size * 10 + 3, "Score to win:");
	mvprintw(2, map->size * 10 + 7, "%d", WIN_VALUE);
	mvprintw(4, map->size * 10 + 3, "Score:");
	mvprintw(5, map->size * 10 + 7, "%d", map->score);
	mvprintw((map->size - 1) * 5 + 0, map->size * 10 + 3, "Instruction");
	mvprintw((map->size - 1) * 5 + 2, map->size * 10 + 3, "ARROW : move piece");
	mvprintw((map->size - 1) * 5 + 3, map->size * 10 + 3, "R     : replay");
	mvprintw((map->size - 1) * 5 + 4, map->size * 10 + 3, "ESC   : exit");
}

void	init_board(t_map *map)
{
	add_random(map);
	add_random(map);
	erase();
	refresh();
	print_board(map);
	check_win(map);
}

void	reset_game(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->size)
	{
		j = 0;
		while (j < map->size)
		{
			map->board[i][j] = 0;
			j++;
		}
		i++;
	}
	map->score = 0;
	map->highest = 0;
	init_board(map);
}

void	run_game(t_map *map)
{
	int	ch;

	init_board(map);
	while (1)
	{
		// Get the keystroke and store in ch to use it later
		ch = getch();
		// Break the loop (get out of the program) if ch == ESC
		if (ch == 27)
			break ;
		else if (ch == 'r')
			reset_game(map);
		else if (ch == KEY_UP || ch == KEY_DOWN || ch == KEY_LEFT
				|| ch == KEY_RIGHT)
		{
			// Reset stop array to zero
			reset_stop(map);
			// Do the sliding (maybe change name to slide will be better)
			if (do_direction(map, ch))
				add_random(map);
			// Print the board
			print_board(map);
			// Check if win, tell player.
			check_win(map);
			// Check if lost, tell player and break the loop (get out of the program)
			if (check_lost(map))
				break ;
		}
	}
}

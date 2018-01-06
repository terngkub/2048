/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 14:31:31 by nkamolba          #+#    #+#             */
/*   Updated: 2018/01/06 14:43:56 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void	print_board(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->size)
	{
		j = 0;
		while (j < map->size)
			printw("%d ", map->board[i][j++]);
		printw("\n");
		i++;
	}
	printw("\n");
}

void	run_game(t_map *map)
{
	int	ch;

	initscr();
	noecho();
	cbreak();
	keypad(stdscr, 1);
	while (1)
	{
		ch = getch();
		if (ch == 27)
			break ;
		else if (ch == KEY_UP || ch == KEY_DOWN || ch == KEY_LEFT
				|| ch == KEY_RIGHT)
		{
			add_random(map);
			print_board(map);
		}
	}
	endwin();
}

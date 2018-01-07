/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbergon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 18:30:32 by clbergon          #+#    #+#             */
/*   Updated: 2018/01/07 22:14:05 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void	init_board(t_map *map)
{
	add_random(map);
	add_random(map);
	erase();
	refresh();
	print_board(map);
	check_win(map);
}

static void	reset_game(t_map *map)
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

void		run_game(t_map *map)
{
	int	ch;

	init_board(map);
	while (1)
	{
		ch = getch();
		if (ch == 27)
			break ;
		else if (ch == 'r')
			reset_game(map);
		else if (ch == KEY_UP || ch == KEY_DOWN || ch == KEY_LEFT
				|| ch == KEY_RIGHT)
		{
			reset_stop(map);
			if (do_direction(map, ch))
				add_random(map);
			print_board(map);
		}
	}
}

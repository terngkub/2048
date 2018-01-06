/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_game.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 14:31:31 by nkamolba          #+#    #+#             */
/*   Updated: 2018/01/06 17:50:26 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void	print_board(t_map *map)
{
	size_t	i;
	size_t	j;
	int		width;

	width = ft_numlen(map->best_score);
	move(0, 0);
	i = 0;
	while (i < map->size)
	{
		j = 0;
		while (j < map->size)
		{
			if (map->board[i][j] == 0)
				printw("%*s ", width, ".");
			else
				printw("%*d ", width, map->board[i][j]);
			j++;
		}
		printw("\n");
		i++;
	}
	printw("\n");
	printw("Score: %d\n", map->score);
}

void	run_game(t_map *map)
{
	int	ch;

	print_board(map);
	while (1)
	{
		ch = getch();
		if (ch == 27)
			break ;
		else if (ch == KEY_UP || ch == KEY_DOWN || ch == KEY_LEFT
				|| ch == KEY_RIGHT)
		{
			reset_stop(map);
			add_random(map);
			map->score++;
			map->best_score += 500;
			erase();
			print_board(map);
			check_win(map);
			if (check_lost(map))
				break ;
		}
	}
}

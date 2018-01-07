/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:44:10 by nkamolba          #+#    #+#             */
/*   Updated: 2018/01/07 14:20:38 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int		check_lost(t_map *map)
{
	t_map	*temp_map;
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->size)
	{
		j = 0;
		while (j < map->size)
		{
			if (map->board[i][j++] == 0)
				return (0);
		}
		i++;
	}
	temp_map = create_map(map->size);
	copy_board(temp_map->board, map->board, map->size);
	if (do_direction(temp_map, KEY_UP))
	{
		clean_map(temp_map);
		return (0);
	}
	if (do_direction(temp_map, KEY_DOWN))
	{
		clean_map(temp_map);
		return (0);
	}
	if (do_direction(temp_map, KEY_LEFT))
	{
		clean_map(temp_map);
		return (0);
	}
	if (do_direction(temp_map, KEY_RIGHT))
	{
		clean_map(temp_map);
		return (0);
	}
	if (map->highest >= WIN_VALUE)
		mvprintw(7, map->size * 10 + 3, "Game is over ! Well done ;)");
	else
		// mvprintw(y, x, str) it will print string on coordinate x, y
		mvprintw(7, map->size * 10 + 3, "You lost!");
	mvprintw(8, map->size * 10 + 3, "Press ESC to end the program");
	mvprintw(9, map->size * 10 + 3, "Press 'R' to play again.");
	// wait for player to press ESC
	while (1)
		if (getch() == 27)
			break;
	return (1);
}

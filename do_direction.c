/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_direction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbergon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 14:28:08 by clbergon          #+#    #+#             */
/*   Updated: 2018/01/07 22:17:13 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void			move_left(t_map *map)
{
	int		x;

	x = 0;
	while (x < (int)map->size)
	{
		slide_board(map->board[x], map, 0);
		x++;
	}
}

static void			move_right(t_map *map)
{
	rotate_board(map);
	rotate_board(map);
	move_left(map);
	rotate_board(map);
	rotate_board(map);
}

static void			move_down(t_map *map)
{
	rotate_board(map);
	rotate_board(map);
	rotate_board(map);
	move_left(map);
	rotate_board(map);
}

static void			move_up(t_map *map)
{
	rotate_board(map);
	move_left(map);
	rotate_board(map);
	rotate_board(map);
	rotate_board(map);
}

int					do_direction(t_map *map, int ch)
{
	t_map	*temp_map;

	temp_map = create_map(map->size);
	copy_board(temp_map->board, map->board, map->size);
	if (ch == KEY_UP)
		move_up(map);
	else if (ch == KEY_DOWN)
		move_down(map);
	else if (ch == KEY_RIGHT)
		move_right(map);
	else if (ch == KEY_LEFT)
		move_left(map);
	if (compare_board(temp_map->board, map->board, map->size))
	{
		clean_map(temp_map);
		return (1);
	}
	clean_map(temp_map);
	return (0);
}

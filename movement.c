/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbergon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 19:11:07 by clbergon          #+#    #+#             */
/*   Updated: 2018/01/07 21:21:47 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void		rotate_board(t_map *map)
{
	int		i;
	int		j;
	int		n;
	int		tmp;

	i = 0;
	j = 0;
	n = (int)map->size;
	while (i < n / 2)
	{
		j = i;
		while (j < n - i - 1)
		{
			tmp = map->board[i][j];
			map->board[i][j] = map->board[j][n - i - 1];
			map->board[j][n - i - 1] = map->board[n - i - 1][n - j - 1];
			map->board[n - i - 1][n - j - 1] = map->board[n - j - 1][i];
			map->board[n - j - 1][i] = tmp;
			j++;
		}
		i++;
	}
}

void			move_left(t_map *map)
{
	int		x;

	x = 0;
	while (x < (int)map->size)
	{
		slide_board(map->board[x], map, 0);
		x++;
	}
}

void			move_right(t_map *map)
{
	rotate_board(map);
	rotate_board(map);
	move_left(map);
	rotate_board(map);
	rotate_board(map);
}

void			move_down(t_map *map)
{
	rotate_board(map);
	rotate_board(map);
	rotate_board(map);
	move_left(map);
	rotate_board(map);
}

void			move_up(t_map *map)
{
	rotate_board(map);
	move_left(map);
	rotate_board(map);
	rotate_board(map);
	rotate_board(map);
}

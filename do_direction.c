/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_direction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbergon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 14:28:08 by clbergon          #+#    #+#             */
/*   Updated: 2018/01/07 19:15:20 by clbergon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void			copy_board(int **temp, int **board, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			temp[i][j] = board[i][j];
			j++;
		}
		i++;
	}
}

int				compare_board(int **temp, int **board, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (temp[i][j] != board[i][j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int				do_direction(t_map *map, int ch)
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

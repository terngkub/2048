/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_direction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbergon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 14:28:08 by clbergon          #+#    #+#             */
/*   Updated: 2018/01/07 14:22:27 by nkamolba         ###   ########.fr       */
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
			map->board[i][j] = map->board[j][n-i-1];
			map->board[j][n-i-1] = map->board[n-i-1][n-j-1];
			map->board[n-i-1][n-j-1] = map->board[n-j-1][i];
			map->board[n-j-1][i] = tmp;
			j++;
		}
		i++;
	}
}

int				find_target(int *line, int x, int stop)
{
	int		t;

	t = x - 1;
	if (x == 0)
		return (x);
	while (t >= 0)
	{
		if (line[t] != 0)
		{
			if (line[t] != line[x])
			{
				return (t + 1);
			}
			return (t);
		}
		else if (t == stop)
			return (t);
		t--;
	}
	return (x);
}

static void		slide_board(int *line, t_map *map)
{
	int		x;
	int		t;
	int		stop;

	x = 0;
	t = 0;
	stop = 0;
	while (x < (int)map->size)
	{
		if (line[x] != '\0')
		{
			t = find_target(line, x, stop);
			if (t != x)
			{
				if (line[t] == 0)
					line[t] = line[x];
				else if (line[t] == line[x])
				{
					line[t] *= 2;
					//store highest number
					if (map->highest < line[t])
						map->highest = line[t];
					//merge (increase power of two)
					map->score += line[t];
					//set stop to avoid double merge
					stop = t + 1;
				}
				line[x] = 0;
			}
		}
		x++;
	}
}

static void		move_left(t_map *map)
{
	int		x;

	x = 0;
	while (x < (int)map->size)
	{
		slide_board(map->board[x], map);
		x++;
	}
}

static void		move_right(t_map *map)
{
	rotate_board(map);
	rotate_board(map);
	move_left(map);
	rotate_board(map);
	rotate_board(map);
}

static void		move_down(t_map *map)
{
	rotate_board(map);
	rotate_board(map);
	rotate_board(map);
	move_left(map);
	rotate_board(map);
}

static void		move_up(t_map *map)
{
	rotate_board(map);
	move_left(map);
	rotate_board(map);
	rotate_board(map);
	rotate_board(map);
}

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

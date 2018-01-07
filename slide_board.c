/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   slide_board.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbergon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 19:08:41 by clbergon          #+#    #+#             */
/*   Updated: 2018/01/07 19:51:26 by clbergon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static int	find_target(int *line, int x, int stop)
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

void		slide_board(int *line, t_map *map)
{
	int		x;
	int		t;
	int		stop;

	x = -1;
	stop = 0;
	while (++x < (int)map->size)
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
					if (map->highest < line[t])
						map->highest = line[t];
					map->score += line[t];
					stop = t + 1;
				}
				line[x] = 0;
			}
		}
	}
}

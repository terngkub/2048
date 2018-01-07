/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_random.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbergon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 13:38:26 by clbergon          #+#    #+#             */
/*   Updated: 2018/01/07 19:04:29 by clbergon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static int	get_value(t_map *map)
{
	int		value;

	value = (rand() % 10 == 0) ? 4 : 2;
	if (map->highest < value)
		map->highest = value;
	return (value);
}

void		add_random(t_map *map)
{
	int		x;
	int		y;
	int		len;
	int		list[map->size * map->size][2];

	y = -1;
	len = 0;
	while (++y < (int)map->size)
	{
		x = -1;
		while (++x < (int)map->size)
		{
			if (map->board[y][x] == 0)
			{
				list[len][0] = x;
				list[len][1] = y;
				len++;
			}
		}
	}
	if (len > 0)
	{
		len = rand() % len;
		map->board[list[len][1]][list[len][0]] = get_value(map);
	}
}

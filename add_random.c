/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_random.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbergon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 13:38:26 by clbergon          #+#    #+#             */
/*   Updated: 2018/01/07 17:20:48 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void	add_random(t_map *map)
{
	int		value;
	int		x;
	int		y;
	int		len;
	int		list[map->size * map->size][2];

	x = 0;
	y = 0;
	len = 0;
	value = (rand() % 10 == 0) ? 4 : 2;//assigning 2 or 4 as the new random
	if (map->highest < value)
		map->highest = value;
	while (y < (int)map->size)
	{
		x = 0;
		while (x < (int)map->size)
		{
			if (map->board[y][x] == 0)//listing how many cases of 0 are available
			{
				list[len][0] = x;
				list[len][1] = y;
				len++;
			}
			x++;
		}
		y++;
	}
	if (len > 0)
	{
		len = rand() % len; //assigning random position
		x = list[len][0];
		y = list[len][1];
		map->board[y][x] = value;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_direction.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clbergon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 14:28:08 by clbergon          #+#    #+#             */
/*   Updated: 2018/01/06 14:39:13 by clbergon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void		rotate_map->board(t_map *map)
{
	int		i;
	int		j;
	int		n;
	int		*tmp;

	i = 0;
	j = 0;
	n = (int)map->size;
	while (i < n / 2)
	{
		j = i;
		while ( j < n - 1)
		{
			tmp = map->board[i][j];
			map->board[i][j] = map->board[j][n-i-1];
			map->board[j][n-i-1] = map->board[n-i-1][n-j-1];
			map->board[n-i-1][n-j-1] = map->board[n-j-1][i];
			map->board[n-j-1][i] = tmp;
			j++:
		}
		i++;
	}
}

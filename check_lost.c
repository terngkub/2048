/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_lost.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:44:10 by nkamolba          #+#    #+#             */
/*   Updated: 2018/01/06 17:28:25 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

int		check_lost(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->size)
	{
		j = 0;
		while (j < map->size)
			if (map->board[i][j++] == 0)
				return (0);
		i++;
	}
	mvprintw(6, 0, "You're lost. Please press ESC to end the program.");
	while (1)
		if (getch() == 27)
			break;
	return (1);
}

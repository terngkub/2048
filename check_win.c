/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:43:33 by nkamolba          #+#    #+#             */
/*   Updated: 2018/01/07 13:39:26 by clbergon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void	check_win(t_map *map)
{
	if (map->highest >= WIN_VALUE)
	{
		mvprintw(7, map->size * 10 + 3, "You won!");
		mvprintw(8, map->size * 10 + 3, "How far will you go ?");
		refresh();
	}
}

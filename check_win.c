/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_win.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 15:43:33 by nkamolba          #+#    #+#             */
/*   Updated: 2018/01/06 15:49:15 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void	check_win(t_map *map)
{
	if (map->best_score >=  WIN_VALUE)
		mvprintw(6, 0, "You won! You can continue playing.");
}

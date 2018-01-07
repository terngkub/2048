/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 11:45:20 by nkamolba          #+#    #+#             */
/*   Updated: 2018/01/07 21:49:51 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

size_t		start_game(void)
{
	int		ch;

	g_choice = 4;
	print_menu(g_choice);
	while (1)
	{
		ch = getch();
		if (ch == KEY_DOWN && g_choice < 5)
			g_choice++;
		else if (ch == KEY_UP && g_choice > 4)
			g_choice--;
		else if (ch == 27)
		{
			g_choice = 0;
			break ;
		}
		else if (ch == 10)
			break ;
		print_menu(g_choice);
	}
	return (g_choice);
}

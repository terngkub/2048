/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 11:45:20 by nkamolba          #+#    #+#             */
/*   Updated: 2018/01/07 20:27:02 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

size_t		start_game(void)
{
	int		ch;

	choice = 4;
	print_menu(choice);
	while (1)
	{
		ch = getch();
		if (ch == KEY_DOWN && choice < 5)
			choice++;
		else if (ch == KEY_UP && choice > 4)
			choice--;
		else if (ch == 27)
		{
			choice = 0;
			break ;
		}
		else if (ch == 10)
			break ;
		print_menu(choice);
	}
	return (choice);
}

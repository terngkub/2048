/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 11:45:20 by nkamolba          #+#    #+#             */
/*   Updated: 2018/01/07 13:41:14 by clbergon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void	print_menu_color(char *str, int color)
{
	if (color)
		attron(COLOR_PAIR(1));
	printw(str);
	if (color)
		attroff(COLOR_PAIR(1));
}

static void	print_menu(size_t choice)
{
	erase();
	start_color();
	init_pair(1, COLOR_BLACK, COLOR_WHITE);
	printw("------------------------------\n");
	printw("-           2048             -\n");
	printw("------------------------------\n\n");
	printw("Choose map size\n");
	print_menu_color(">>> Normal: 4 x 4\n", choice == 4);
	print_menu_color(">>> Easy  : 5 x 5\n", choice == 5);
	printw("\nUP/DOWN: select map\n");
	printw("ENTER: start game\n");
	printw("ESC: exit program\n");
}

size_t		start_game(void)
{
	size_t	choice;
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

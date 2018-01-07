/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 11:59:56 by nkamolba          #+#    #+#             */
/*   Updated: 2018/01/07 21:22:56 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static void	handle_resize(int sig)
{
	(void)sig;
	endwin();
	refresh();
	werase(stdscr);
	if (state == 1)
	{
		print_menu(choice);
		refresh();
	}
	else if (state == 2)
		print_board(map);
}

static void	set_screen(void)
{
	initscr();
	noecho();
	curs_set(0);
	cbreak();
	keypad(stdscr, 1);
}

int			check_win_value(void)
{
	int		i;

	i = 2;
	while (i <= WIN_VALUE)
		i *= 2;
	i /= 2;
	if (i != WIN_VALUE)
		return (0);
	return (1);
}

int			main(void)
{
	if (!check_win_value())
		return (0);
	set_screen();
	signal(SIGWINCH, handle_resize);
	state = 1;
	if ((choice = start_game()))
	{
		if (!(map = create_map(choice)))
			return (1);
		state = 2;
		run_game(map);
		clean_map(map);
	}
	endwin();
	return (0);
}

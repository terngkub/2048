/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 11:59:56 by nkamolba          #+#    #+#             */
/*   Updated: 2018/01/07 18:09:58 by clbergon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

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
	size_t	choice;
	t_map	*map;

	if (!check_win_value())
		return (0);
	set_screen();
	if ((choice = start_game()))
	{
		if (!(map = create_map(choice)))
			return (1);
		run_game(map);
		clean_map(map);
	}
	endwin();
	return (0);
}

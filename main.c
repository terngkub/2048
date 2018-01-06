/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 11:59:56 by nkamolba          #+#    #+#             */
/*   Updated: 2018/01/06 15:42:23 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

/*
static void	print_2d_arr(int **arr, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
			ft_printf("%d ", arr[i][j++]);
		ft_printf("\n");
		i++;
	}
}
*/

static void	set_screen(void)
{
	initscr();
	noecho();
	cbreak();
	keypad(stdscr, 1);
}

int			main(void)
{
	t_map	*map;

	if (!(map = create_map(4)))
		return (1);
	set_screen();
	run_game(map);
	endwin();
	clean_map(map);
	return (0);
}

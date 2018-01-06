/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 11:59:56 by nkamolba          #+#    #+#             */
/*   Updated: 2018/01/06 14:40:53 by nkamolba         ###   ########.fr       */
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

int			main(void)
{
	t_map	*map;

	if (!(map = create_map(4)))
		return (1);
	run_game(map);
	/*
	ft_printf("board\n");
	print_2d_arr(map->board, map->size);
	ft_printf("test edit board\n");
	map->board[2][3] = 2;
	map->board[0][0] = 2;
	print_2d_arr(map->board, map->size);
	ft_printf("size\n");
	print_2d_arr(map->stop, map->size);
	ft_printf("test edit stop\n");
	map->stop[2][3] = 1;
	map->stop[0][0] = 1;
	print_2d_arr(map->stop, map->size);
	*/
	return (0);
}

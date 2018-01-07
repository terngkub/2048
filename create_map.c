/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 11:46:07 by nkamolba          #+#    #+#             */
/*   Updated: 2018/01/07 13:04:23 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

static int	**create_2d_arr(size_t size)
{
	int		**arr;
	size_t	i;

	if (!(arr = (int **)ft_memalloc(sizeof(int *) * size)))
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (!(arr[i] = (int *)ft_memalloc(sizeof(int) * size)))
			return (NULL);
		i++;
	}
	return (arr);
}

t_map		*create_map(size_t size)
{
	t_map	*map;

	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		return (NULL);
	map->size = size;
	if (!(map->board = create_2d_arr(size)))
		return (NULL);
	if (!(map->stop = create_2d_arr(size)))
		return (NULL);
	map->score = 0;
	map->highest = 0;
	return (map);
}

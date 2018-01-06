#include "game_2048.h"

void	add_random(t_map *map)
{

	int   value;
	int   x;
	int   y;
	int		random;
	int		len;
	int		list[map->size * map->size][2];

	x = 0;
	y = 0;
	random = 0;
	len = 0;
	//n = 0;
	value = (rand() % 10 == 1) ? 4 : 2;
	while (y < (int)map->size)
	{
		x = 0;
		while (x < (int)map->size)
		{
			if (map->board[y][x] == 0)
			{
				list[len][0] = x;
				list[len][1] = y;
				len++;
			}
			x++;
		}
		y++;
	}
	if (len > 0)
	{
		random = rand() % len;
		x = list[random][0];
		y = list[random][1];
		map->board[y][x] = value;
	}
}

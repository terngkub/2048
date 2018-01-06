#include "game_2048.h"

void	add_random(t_map *map)
{
	static bool initialized = false;
	int   x;
  int   y;
	int   r;
  int   len;
	int   n; 
  int   list[map->size * map->size][2];

  x = 0;
  y = 0;
  r = 0;
  n = 0;
  len = 0;
	if (!initialized)
  {
		srand(time(NULL));
		initialized = true;
	}
	while (x < (int)map->size)
  {
    y = 0;
		while (y < (int)map->size)
    {
			if (map->board[x][y] == 0)
      {
				list[len][0] = x;
				list[len][1] = y;
				len++;
			}
      y++;
		}
	}
	if (len > 0)
  {
		r = rand() % len;
		x = list[r][0];
		y = list[r][1];
		n = (rand() % 10) / 9 + 1;
		map->board[x][y] = n;
	}
}

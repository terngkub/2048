/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 11:43:15 by nkamolba          #+#    #+#             */
/*   Updated: 2018/01/06 16:13:45 by clbergon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_2048_H
# define GAME_2048_H

# include "libft/libft.h"
# include <ncurses.h>
# include <time.h>

enum			e_const
{
	WIN_VALUE = 2048
};

typedef struct	s_map
{
	size_t		size;
	int			**board;
	int			**stop;
	int			score;
	int			best_score;
}				t_map;

t_map			*create_map(size_t size);
void			run_game(t_map *map);
void			reset_stop(t_map *map);
void			check_win(t_map *map);
int				check_lost(t_map *map);
void			clean_map(t_map *map);
void			add_random(t_map *map);


#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 11:43:15 by nkamolba          #+#    #+#             */
/*   Updated: 2018/01/07 21:54:18 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_2048_H
# define GAME_2048_H

# include "libft/libft.h"
# include <ncurses.h>

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
	int			highest;
}				t_map;

size_t			start_game(void);
void			print_menu(size_t choice);
t_map			*create_map(size_t size);
void			run_game(t_map *map);
void			reset_stop(t_map *map);
void			check_win(t_map *map);
int				check_lost(t_map *map);
void			clean_map(t_map *map);
void			add_random(t_map *map);
void			copy_board(int **temp, int **board, size_t size);
int				do_direction(t_map *map, int ch);
int				print_board(t_map *map);
void			slide_board(int *line, t_map *map, int stop);
void			move_left(t_map *map);
void			move_right(t_map *map);
void			move_up(t_map *map);
void			move_down(t_map *map);
int				log_two(int n);
void			clean_window(WINDOW ***win, size_t size);

int				g_state;
size_t			g_choice;
t_map			*g_map;

#endif

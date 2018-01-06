/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 11:43:15 by nkamolba          #+#    #+#             */
/*   Updated: 2018/01/06 12:20:49 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_2048_H
# define GAME_2048_H

# include "libft/libft.h"

enum			e_const
{
	WIN_VALUE = 2048
};

typedef struct	s_map
{
	size_t		size;
	int			**board;
	int			**stop;
	int			best_score;
}				t_map;

t_map			*create_map(size_t size);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkamolba <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/07 21:44:06 by nkamolba          #+#    #+#             */
/*   Updated: 2018/01/07 21:44:20 by nkamolba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game_2048.h"

void		clean_window(WINDOW ***win, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		free(win[i]);
		i++;
	}
	free(win);
}

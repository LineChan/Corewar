/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual_end.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/27 22:04:04 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_visual.h"
#include <ncurses.h>

void	ft_visual_end(t_visual *this)
{
  	nocbreak();
	curs_set(1);
  	echo();
  	delwin(this->win);
	endwin();
}

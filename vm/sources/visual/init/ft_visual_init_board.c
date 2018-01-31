/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual_init_board.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/28 23:30:33 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual/ft_visual_board.h"

void		ft_visual_init_board(t_visual_board *this)
{
    this->win = newwin(66, 195, 0, 0);
    box(this->win, '|', '-');
    wrefresh(this->win);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual_init_footer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/28 23:29:20 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visual/ft_visual_footer.h"

void        ft_visual_init_footer(t_visual_footer *this)
{
    this->win = newwin(3, 285, 67, 0);
    box(this->win, '|', '-');
    wattron(this->win, COLOR_PAIR(0) | A_BOLD);
    mvwprintw(this->win, 5, 15, "Live per round: 0");
    mvwprintw(this->win, 7, 15, "Last cycle: 0");
    wattroff(this->win, COLOR_PAIR(0) | A_BOLD);
    wrefresh(this->win);
}

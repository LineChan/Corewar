/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual_refresh_player.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoelling <Zoelling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoelling          #+#    #+#             */
/*   Updated: 2018/01/31 14:55:29 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_visual.h"
#include "ft_vm.h"
#include <unistd.h>

#include "ft_printf.h"
void	ft_visual_refresh_player(t_visual_player const *this, t_proc const *process)
{
	WINDOW	*win;

	win = this->win[process->parent_nb];
	wattron(win, COLOR_PAIR(0) | A_BOLD);
	mvwprintw(win, 5, 15, "Live per round: %d", process->live_per_round);
	mvwprintw(win, 7, 15, "Last cycle: %d", process->has_lived);
	wattroff(win, COLOR_PAIR(0) | A_BOLD);
    wrefresh(win);
}

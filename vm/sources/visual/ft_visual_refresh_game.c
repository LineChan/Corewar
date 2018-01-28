/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual_refresh_game.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoelling <Zoelling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoelling          #+#    #+#             */
/*   Updated: 2018/01/28 23:40:37 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include <unistd.h>

void		ft_visual_refresh_game(t_visual const *this, t_vm const *vm)
{
    wattron(this->win_info, COLOR_PAIR(0) | A_BOLD);
    mvwprintw(this->win_info, 10, 15, "Speed: %d cycles/s", 1000000 / this->refresh);
    mvwprintw(this->win_info, 12, 15, "Cycle: %d", vm->current_cycle);
    mvwprintw(this->win_info, 14, 15, "Process: %d  ", vm->nb_proc);
    mvwprintw(this->win_info, 10, 50, "Cycle-to-die: %d  ", vm->cycle_to_die);
    mvwprintw(this->win_info, 12, 50, "Checks: %d/%d    ", vm->check, MAX_CHECKS);
    mvwprintw(this->win_info, 14, 50, "Nbr live: %d/%d    ", vm->total_live, NBR_LIVE);
    mvwprintw(this->win_info, 16, 25, "Current winner:");
    wattroff(this->win_info, COLOR_PAIR(0) | A_BOLD);
    wattron(this->win_info, COLOR_PAIR(vm->last_alive) | A_BOLD);
    mvwprintw(this->win_info, 16, 41, "%s                  ",
        vm->header[vm->last_alive - 1].prog_name);
    wattroff(this->win_info, COLOR_PAIR(vm->last_alive) | A_BOLD);
    wrefresh(this->win_info);
}

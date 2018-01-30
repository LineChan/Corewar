/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual_refresh_player_kill.c                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoelling <Zoelling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoelling          #+#    #+#             */
/*   Updated: 2018/01/29 15:56:02 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_visual.h"
#include <unistd.h>

static char const	*g_player_state[] =
{
	"   __       ",
	"  /_/\\/\\    ",
	"  \\_\\  /    ",
	"  /_/  \\    ",
	"  \\_\\/\\ \\   ",
	"     \\_\\/   ",
    "    dead    "
};

void	ft_visual_refresh_player_kill(t_visual const *this, t_proc const *proc)
{
	WINDOW	*win;
	size_t	i;

	i = 0;
	win = this->win_player[proc->proc_nb - 1];
    wattron(win, COLOR_PAIR(3) | A_BOLD);
    while (i < sizeof(g_player_state) / sizeof(g_player_state[0]))
    {
    	mvwprintw(win, 1 + i, 60, "%s", g_player_state[i]);
    	++i;
    }
    wattroff(win, COLOR_PAIR(3) | A_BOLD);
    wrefresh(win);
}

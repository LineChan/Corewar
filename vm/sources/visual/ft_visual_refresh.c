/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual_refresh.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoelling <Zoelling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoelling          #+#    #+#             */
/*   Updated: 2018/01/29 18:05:59 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include <unistd.h>

static int	ft_visual_refresh_get_color(t_visual const *this, int offset)
{
	if (0 != this->pc_position[offset])
		return (COLOR_PAIR(VISUAL_PC(this->pc_position[offset])));
	return (COLOR_PAIR(this->color[offset]));
}

void		ft_visual_refresh(t_visual const *this, t_vm const *vm)
{
	int		i;
	int		color;
	uint8_t	val;

	i = 0;
	while (i < MEM_SIZE)
	{
		color = ft_visual_refresh_get_color(this, i);
		wattron(this->win, color);
		//val = (0 == vm->option.stealth) ? this->arena[i] : 0;
		val = vm->arena[i];
		mvwprintw(this->win, 1 + (i >> 6), 2 + (i & 63) * 3, "%02hhx", val);
		wattroff(this->win, color);
		++i;
	}
	wrefresh(this->win);
	ft_visual_refresh_game(this, vm);
	usleep(this->refresh);
}

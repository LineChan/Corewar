/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual_refresh_board.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoelling <Zoelling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoelling          #+#    #+#             */
/*   Updated: 2018/01/30 22:25:41 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_vm.h"
#include <unistd.h>

static int	ft_visual_refresh_get_color(t_visual_board const *this, int offset)
{
	if (0 != this->pc_position[offset])
		return (COLOR_PAIR(VISUAL_PC(this->pc_position[offset])));
	return (COLOR_PAIR(this->color[offset]));
}

void		ft_visual_refresh_board(t_visual_board const *this, t_vm const *vm)
{
//	char	buf[4];
	int		i;
	int		color;
	uint8_t	val;

	i = 0;
	while (i < MEM_SIZE)
	{
		color = ft_visual_refresh_get_color(this, i);
		wattron(this->win, color);
		val = (0 == vm->opt.stealth) ? vm->arena[i] : 0;
		// ft_sprintf(buf, "%02hhx", val);
		// if ('0' == buf[0])
		// 	buf[0] = ' ';
		// if ('0' == buf[1])
		// 	buf[1] = ' ';
		// mvwprintw(this->win, 1 + (i >> 6), 2 + (i & 63) * 3, "%c%c", buf[0], buf[1]);
		mvwprintw(this->win, 1 + (i >> 6), 2 + (i & 63) * 3, "%02hhx", val);
		wattroff(this->win, color);
		++i;
	}
	wrefresh(this->win);
}

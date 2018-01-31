/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoelling <Zoelling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoelling          #+#    #+#             */
/*   Updated: 2018/01/30 20:53:57 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_visual.h"
#include "ft_vm.h"
#include "libft.h"
#include "ft_vm.h"
#include <locale.h>
#include <unistd.h>
#include <sys/ioctl.h>

static int	ft_visual_window_checker(void)
{
	static int const	x = 70;
	static int const	y = 285;
	struct winsize		win;

	if (0 > ioctl(0, TIOCGWINSZ, (void *)&win))
		ft_printf("Error: Can't access to window informations\n");
	else if (win.ws_row < x || win.ws_col < y)
		ft_printf("Error: The window is too small: %d/%d %d/%d\n",
			win.ws_col, win.ws_row, y, x);
	else
		return (1);
	return (0);
}

void		ft_visual_start(t_vm *vm)
{
	while (0 && !ft_visual_window_checker())
		usleep(500000);
	initscr();
	keypad(stdscr, TRUE);
	noecho();
	cbreak();
	curs_set(0);
	timeout(-1);
	start_color();
    init_pair(0, COLOR_BLACK, COLOR_BLACK);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
    init_pair(2, COLOR_BLUE, COLOR_BLACK);
    init_pair(3, COLOR_RED, COLOR_BLACK);
    init_pair(4, COLOR_CYAN, COLOR_BLACK);
	init_pair(1 + MAX_PLAYERS, COLOR_BLACK, COLOR_GREEN);
    init_pair(2 + MAX_PLAYERS, COLOR_BLACK, COLOR_BLUE);
    init_pair(3 + MAX_PLAYERS, COLOR_BLACK, COLOR_RED);
    init_pair(4 + MAX_PLAYERS, COLOR_BLACK, COLOR_CYAN);
    ft_visual_init_board(&vm->visual.board);
    ft_visual_init_header(&vm->visual.header);
    ft_visual_init_footer(&vm->visual.footer);
    ft_visual_init_player(&vm->visual.player, vm);
}

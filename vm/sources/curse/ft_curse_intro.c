/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_curse_intro.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 17:56:12 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/27 00:54:49 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_curse.h"
#include "ft_vm.h"

#include "ft_printf.h"
#if 0
static void			ft_curse_display(void)
{
	//ft_curse_draw_border(ARENA);
	refresh();
	while (getch() != 10)
		;
}
#endif

void			ft_curse_intro(void)
{
	int		parent_x;
	int		parent_y;

	(void)parent_x;
	(void)parent_y;
	#if 0
	ft_printf("COUCOU\n");
	initscr();
	cbreak();
	curs_set(0);
	getmaxyx(stdscr, parent_y, parent_x);
	//keypad()

	ARENA = newwin(parent_y, parent_x - SCORE_SIZE, 0, 0);
	SCORE = newwin(parent_y, parent_x - SCORE_SIZE, 0, parent_x - SCORE_SIZE);
	keypad(ARENA, 1);
	keypad(SCORE, 1);
	//ft_curse_display();
	#endif
	#if 0
	CURSE = newwin(parent_y - SCORE_SIZE, parent_x, 0, 0);
	SCORE = newwin(SCORE_SIZE, parent_x, parent_y - SCORE_SIZE, 0);
	#endif
}

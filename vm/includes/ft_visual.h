/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoelling <Zoelling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoelling          #+#    #+#             */
/*   Updated: 2018/01/29 21:58:03 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VISUAL_H
# define FT_VISUAL_H

# include <stdint.h>
# include <ncurses.h>
# include "op.h"

# define VISUAL_PC(x)	((x) + MAX_PLAYERS)

struct s_vm;
struct s_proc;

# define FOOTER_SIZE	(283)

typedef struct 			s_footer_queue
{
	char				buf[FOOTER_SIZE];
	uint8_t 			color[FOOTER_SIZE];
}						t_footer_queue;

typedef struct			s_visual
{
	/* refresh is set to 20,000.
	   1,000,000 / 20,000 = 20 cycles per second */
	int 				refresh;
	/* Window containg the arena */
	WINDOW				*win;
	uint8_t				arena[MEM_SIZE];
	uint8_t				color[MEM_SIZE];
	uint8_t				pc_position[MEM_SIZE];

	/* Window containing game information */
	WINDOW 				*win_info;
	/* Window containing players informations */
	WINDOW				*win_player[4];
	/* Footer */
	WINDOW 				*win_footer;
	t_footer_queue		circular_queue;
}						t_visual;

void					ft_visual_start(struct s_vm *this);

void					ft_visual_refresh(t_visual const *this, struct s_vm const *vm);

void					ft_visual_refresh_game(t_visual const *this, struct s_vm const *vm);

void					ft_visual_refresh_player(t_visual const *this, struct s_proc const *proc);
void					ft_visual_refresh_player_kill(t_visual const *this, struct s_proc const *proc);

void					ft_visual_refresh_footer(t_visual *this, char const *name, int color);

void					ft_visual_end(t_visual *this);
void					ft_visual_update_arena(struct s_vm *vm,
												struct s_proc const *proc);

#endif

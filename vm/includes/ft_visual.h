/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/28 18:14:26 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VISUAL_H
# define FT_VISUAL_H

# include <stdint.h>
# include <ncurses.h>
# include "op.h"

# define VISUAL_PC(x)	((x) + MAX_PLAYERS)

struct s_vm;
struct s_process;

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

void					ft_visual_refresh_player(t_visual const *this, struct s_process const *process);
void					ft_visual_refresh_player_kill(t_visual const *this, struct s_process const *process);

void					ft_visual_refresh_footer(t_visual *this, char const *name, int color);

void					ft_visual_end(t_visual *this);

#endif

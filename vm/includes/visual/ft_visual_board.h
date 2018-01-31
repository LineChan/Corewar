/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual_board.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/28 23:15:28 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VISUAL_BOARD_H
# define FT_VISUAL_BOARD_H

# include <stdint.h>
# include <ncurses.h>
# include "op.h"

# define VISUAL_PC(x)	((x) + MAX_PLAYERS)

struct s_vm;

typedef struct			s_visual_board
{
	WINDOW				*win;
	uint8_t				arena[MEM_SIZE];
	uint8_t				color[MEM_SIZE];
	uint8_t				pc_position[MEM_SIZE];
}						t_visual_board;

void					ft_visual_init_board(t_visual_board *this);

void					ft_visual_refresh_board(t_visual_board const *this, struct s_vm const *vm);

#endif

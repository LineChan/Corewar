/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/28 23:56:37 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VISUAL_H
# define FT_VISUAL_H

# include <stdint.h>
# include <ncurses.h>
# include "op.h"

# include "visual/ft_visual_header.h"
# include "visual/ft_visual_footer.h"
# include "visual/ft_visual_player.h"
# include "visual/ft_visual_board.h"

typedef struct			s_visual
{
	t_visual_board		board;
	t_visual_header		header;
	t_visual_footer		footer;
	t_visual_player		player;
}						t_visual;

void					ft_visual_start(struct s_vm *this);

void					ft_visual_refresh(t_visual *this, struct s_vm const *vm);

void					ft_visual_end(t_visual *this);

#endif

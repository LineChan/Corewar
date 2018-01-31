/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual_player.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoelling <Zoelling@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoelling          #+#    #+#             */
/*   Updated: 2018/01/30 21:43:37 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VISUAL_PLAYER_H
# define FT_VISUAL_PLAYER_H

# include <stdint.h>
# include <ncurses.h>

struct s_vm;
struct s_proc;

typedef struct			s_visual_player
{
	WINDOW				*win[4];
}						t_visual_player;

void					ft_visual_init_player(t_visual_player *player, struct s_vm const *vm);

void					ft_visual_refresh_player(t_visual_player const *this, struct s_proc const *process);

void					ft_visual_refresh_player_kill(t_visual_player const *this, struct s_proc const *process);

#endif

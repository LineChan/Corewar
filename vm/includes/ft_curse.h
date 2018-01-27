/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_curse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 17:40:53 by mvillemi          #+#    #+#             */
/*   Updated: 2018/01/27 00:51:19 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CURSE_H
# define FT_CURSE_H

/*
** Libraries
*/
# include <ncurses.h>

/*
** Defines
*/

# define ARENA			ft_arena_sig()->win
# define SCORE			ft_score_sig()->win
# define SCORE_SIZE		20

/*
** Structures
*/

typedef struct			s_curse_manager
{
	int			ncurse_mode;
	WINDOW		*win;
}						t_curse_manager;

t_curse_manager		*ft_arena_sig(void);
t_curse_manager		*ft_score_sig(void);

/*
** Prototypes
*/

void		ft_curse_intro(void);
void		ft_curse_del(void);
void		ft_curse_draw_border(WINDOW *screen);
//void		ft_curse_
//void		ft_visual_
#endif

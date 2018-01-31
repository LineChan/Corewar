/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual_footer.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/28 23:15:24 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VISUAL_FOOTER_H
# define FT_VISUAL_FOOTER_H

# include <stdint.h>
# include <ncurses.h>

struct s_vm;

# define FOOTER_SIZE	(283)

typedef struct			s_visual_footer
{
	WINDOW				*win;
	char				buf[FOOTER_SIZE];
	uint8_t 			color[FOOTER_SIZE];
}						t_visual_footer;

void					ft_visual_init_footer(t_visual_footer *this);

void					ft_visual_refresh_footer(t_visual_footer *this, char const *name, int color);

#endif

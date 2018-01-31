/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_visual_header.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igomez <igomez@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2018/01/28 23:15:26 by igomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VISUAL_HEADER_H
# define FT_VISUAL_HEADER_H

# include <stdint.h>
# include <ncurses.h>

struct s_vm;

typedef struct			s_visual_header
{
	WINDOW				*win;
	int					refresh;
}						t_visual_header;

void					ft_visual_init_header(t_visual_header *this);

void					ft_visual_refresh_header(t_visual_header const *this, struct s_vm const *vm);

#endif

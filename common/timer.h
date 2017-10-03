/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/10/04 00:37:09 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TIMER_H
# define FT_TIMER_H

# include <time.h>

typedef struct	s_timer
{	
	clock_t		in;
	clock_t		out;
}				t_timer;

void	ft_timer_start(t_timer *timer);

void	ft_timer_stop(t_timer *timer);

float	ft_timer_diff(t_timer *timer);

#endif

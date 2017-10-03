/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/10/04 00:35:38 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "timer.h"

void	ft_timer_start(t_timer *timer)
{
	timer->in = clock();
}

void	ft_timer_stop(t_timer *timer)
{
	timer->out = clock();
}

float	ft_timer_diff(t_timer *timer)
{
	return ((float)(timer->out - timer->in) / CLOCKS_PER_SEC);
}

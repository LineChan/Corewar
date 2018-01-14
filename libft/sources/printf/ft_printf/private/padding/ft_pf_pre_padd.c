/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_pre_padd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/27 02:35:02 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/10/31 13:40:55 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_pf_impl.h"

void	ft_pf_pre_padd(t_pf_buf *p, size_t n, t_printf *pf)
{
	int32_t		c;
	int32_t		len;

	if (~pf->flags & PF_FLAG_MINUS)
	{
		if (PF_FLAG_ZERO & pf->flags)
			c = '0';
		else
			c = ' ';
		len = (int32_t)n;
		while (len < pf->width)
		{
			ft_pf_buffer_add(p, c);
			--pf->width;
		}
	}
}

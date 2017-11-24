/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_prepadd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/27 02:35:02 by Zoellingam        #+#    #+#             */
/*   Updated: 2016/12/20 16:28:54 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_engine.h"

void	ft_printf_prepadd(char **p, size_t n, t_printf_syntax *pf)
{
	uint8_t	c;

	c = (pf->flags & FT_P_ZEROPAD) ? '0' : ' ';
	if (!(pf->flags & FT_P_LEFT))
		while ((int)n < pf->width--)
			*((*p)++) = c;
}

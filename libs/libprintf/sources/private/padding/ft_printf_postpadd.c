/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_postpadd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/27 02:35:02 by Zoellingam        #+#    #+#             */
/*   Updated: 2016/12/20 16:28:42 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_engine.h"

void	ft_printf_postpadd(char **p, size_t n, t_printf_syntax *pf)
{
	uint8_t	c;

	c = (pf->flags & FT_P_ZEROPAD) ? '0' : ' ';
	while ((int)n < pf->width--)
		*((*p)++) = c;
}

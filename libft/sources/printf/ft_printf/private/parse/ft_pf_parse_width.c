/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_parse_width.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/10/31 13:41:09 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_pf_impl.h"

static int	ft_pf_wildcard(char **fmt, va_list ap, t_printf *pf)
{
	int32_t	width;

	++(*fmt);
	width = va_arg(ap, int32_t);
	if (0 > width)
	{
		width = -width;
		pf->flags |= PF_FLAG_MINUS;
	}
	return (width);
}

int			ft_pf_parse_width(char **fmt, va_list ap, t_printf *pf)
{
	int		width;

	if ('*' == **fmt)
	{
		if (10 > (uint8_t)((*fmt)[1] - '0'))
		{
			++(*fmt);
			width = va_arg(ap, int32_t);
		}
		else
			return (ft_pf_wildcard(fmt, ap, pf));
	}
	width = 0;
	if ('-' == **fmt)
	{
		pf->flags |= PF_FLAG_MINUS;
		++(fmt);
	}
	while (10 > (uint8_t)(**fmt - '0'))
		width = (width << 3) + (width << 1) + (*(*fmt)++ - '0');
	if ('*' == **fmt)
		return (ft_pf_wildcard(fmt, ap, pf));
	return (width);
}

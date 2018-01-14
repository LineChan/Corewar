/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_parse_precision.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/10/31 13:41:04 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_pf_impl.h"

int		ft_pf_parse_precision(char **fmt, va_list ap, t_printf *pf)
{
	int		prec;

	if ('.' != **fmt)
		return (-1);
	++(*fmt);
	if ('*' == **fmt)
	{
		prec = (int32_t)va_arg(ap, int32_t);
		if (0 > prec)
			prec = -1;
		++(*fmt);
	}
	else
	{
		prec = 0;
		while (10 > (uint8_t)(**fmt - '0'))
		{
			prec = (prec << 3) + (prec << 1) + (**fmt - '0');
			++(*fmt);
		}
	}
	return (prec);
	(void)pf;
}

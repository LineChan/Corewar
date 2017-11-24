/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsnprintf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/27 02:22:54 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/03/16 17:38:02 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_engine.h"
#include "ft_printf.h"
#include "ft_string.h"

int		ft_vsnprintf(char *buf, size_t n, char const *format, va_list ap)
{
	size_t r;

	ft_printf_engine(buf, format, ap);
	r = ft_strlen(buf);
	if (r > n)
		ft_memset(buf + n, 0, r - n);
	return (r);
}

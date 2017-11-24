/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vsprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/27 02:22:54 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/03/18 11:21:54 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int		ft_vsprintf(char *buf, char const *format, va_list ap)
{
	return (ft_vsnprintf(buf, INT_MAX >> 1, format, ap));
}

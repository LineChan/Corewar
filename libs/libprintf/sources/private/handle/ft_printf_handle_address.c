/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_handle_address.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/27 02:27:32 by Zoellingam        #+#    #+#             */
/*   Updated: 2016/12/20 16:11:17 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_engine.h"

static void		ft_printf_handle_v6addr(
					char **p,
					uint8_t *addr,
					t_printf_syntax *pf)
{
	char	tmp[24];
	char	*digit;
	int		i;
	int		n;

	digit = (pf->flags & FT_P_UPPERCASE) ? FT_P_UPPER_DIGIT : FT_P_LOWER_DIGIT;
	n = 0;
	i = 0;
	while (i < 6)
	{
		if (0 != i)
			*(tmp + n++) = ':';
		*(tmp + n++) = *(digit + (*(addr + i) >> 0x04));
		*(tmp + n++) = *(digit + (*(addr + i++) & 0xf));
	}
	ft_printf_prepadd(p, n, pf);
	i = 0;
	while (i < n)
		*((*p)++) = *(tmp + i++);
	ft_printf_postpadd(p, n, pf);
}

static void		ft_printf_fill_v4addr(char **p, uint8_t *addr)
{
	char	*digit;
	int		i;
	int		n;

	i = 0;
	digit = FT_P_LOWER_DIGIT;
	while (i < 4)
	{
		if (i != 0)
			*((*p)++) = '.';
		n = addr[i++];
		if (n >= 100)
		{
			*((*p)++) = *(digit + (n / 100));
			n %= 100;
		}
		if (n >= 10)
		{
			*((*p)++) = *(digit + (n / 10));
			n %= 10;
		}
		*((*p)++) = *(digit + n);
	}
}

static void		ft_printf_handle_v4addr(
					char **p,
					uint8_t *addr,
					t_printf_syntax *pf)
{
	char	tmp[24];
	char	*s;
	int		i;

	s = tmp;
	ft_printf_fill_v4addr(&s, addr);
	ft_printf_prepadd(p, s - tmp, pf);
	i = 0;
	while (i < (s - tmp))
		*((*p)++) = *(tmp + i++);
	ft_printf_postpadd(p, s - tmp, pf);
}

void			ft_printf_handle_address(
					char **p,
					t_printf_syntax *pf,
					va_list ap)
{
	uint8_t *s;

	s = va_arg(ap, uint8_t *);
	if ('l' == pf->qualifier)
		ft_printf_handle_v6addr(p, s, pf);
	else
		ft_printf_handle_v4addr(p, s, pf);
}

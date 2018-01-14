/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pf_wctomb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/04 11:33:27 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/10/31 13:38:12 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include <errno.h>

int         ft_pf_wctomb(char *buf, wchar_t wc)
{
    if (wc <= 0x7f)
    {
        if (0 != buf)
            buf[0] = wc;
        return (1);
    }
    if (wc >= 0x80 && wc <= 0x7ff)
    {
        if (0 != buf)
        {
            buf[0] = 0xc0 | ((wc & 0x7c0) >> 6);
            buf[1] = 0x80 | (wc & 0x3f);
        }
        return (2);
   }
   if (wc >= 0x800 && wc <= 0xffff)
   {
        if (0 != buf)
        {
         /* UTF-16 surrogates -- must not occur in normal UCS-4 data */
            if (wc >= 0xd800 && wc <= 0xdfff)
            {
                errno = EILSEQ;
                return (0);
            }
            buf[0] = 0xe0 | ((wc & 0xf000) >> 12);
            buf[1] = 0x80 | ((wc & 0xfc0) >> 6);
            buf[2] = 0x80 | (wc & 0x3f);
        }
        return (3);
   }
   if (wc >= 0x10000 && wc <= 0x1fffff)
   {
        if (0 != buf)
        {
            buf[0] = 0xf0 | ((wc & 0x1c0000) >> 18);
            buf[1] = 0x80 | ((wc & 0x3f000) >> 12);
            buf[2] = 0x80 | ((wc & 0xfc0) >> 6);
            buf[3] = 0x80 | (wc & 0x3f);
        }
        return (4);
   }
   if (wc >= 0x200000 && wc <= 0x3ffffff)
   {
        if (0 != buf)
        {
            buf[0] = 0xf8 | ((wc & 0x3000000) >> 24);
            buf[1] = 0x80 | ((wc & 0xfc0000) >> 18);
            buf[1] = 0x80 | ((wc & 0x3f000) >> 12);
            buf[3] = 0x80 | ((wc & 0xfc0) >> 6);
            buf[4] = 0x80 | (wc & 0x3f);
        }
        return (5);
   }
   if (wc >= 0x4000000 && wc <= 0x7fffffff)
   {
        if (0 != buf)
        {
            buf[0] = 0xfc | ((wc & 0x40000000) >> 30);
            buf[1] = 0x80 | ((wc & 0x3f000000) >> 24);
            buf[2] = 0x80 | ((wc & 0xfc0000) >> 18);
            buf[3] = 0x80 | ((wc & 0x3f000) >> 12);
            buf[4] = 0x80 | ((wc & 0xfc0) >> 6);
            buf[5] = 0x80 | (wc & 0x3f);
        }
        return (6);
   }
   return (0);
}
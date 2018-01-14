/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/11/25 13:21:23 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "private/ft_ctype_private.h"
#include "ft_ctype.h"

int    ft_isupper(int c)
{
    return (ft_ctype_mask(c, 1 << FT_CTYPE_ISUPPER));
}

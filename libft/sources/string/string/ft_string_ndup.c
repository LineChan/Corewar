/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_ndup.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/08/15 23:33:52 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

t_string    *ft_string_ndup(char const *str, size_t len)
{
    t_string    *new;
    size_t      nb;

    nb = ft_strnlen(str, len);
    new = ft_string_new(nb);
    ft_strncpy(new->str, str, nb);
    new->len = nb;
    return (new);
}

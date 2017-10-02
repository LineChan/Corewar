/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/10/02 01:15:07 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

/*
**	Malloc errors aren't catched as long as the standards does not define
**	these kind of behaviors:
**    - https://linux.die.net/man/3/malloc
**    - http://linuxfr.org/users/gouttegd/journaux/gestion-des-erreurs-d-allocation-memoire-en-c
*/
void    *ft_memalloc(size_t size)
{
    return (ft_memset(malloc(size), 0, size));
}

void    *ft_calloc(size_t nb, size_t size)
{
    return (ft_memalloc(nb * size));
}

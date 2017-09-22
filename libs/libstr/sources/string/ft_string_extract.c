/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_extract.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/04/02 14:37:29 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

t_string	*ft_string_extract(t_string *string, char const *to_find)
{
	size_t	len;
	char	*pos;

	if (0 != (pos = ft_strstr(string->str, to_find)))
	{
		len = ft_strlen(to_find);
		ft_string_remove(string, pos - string->str, len);
	}
	return (string);
}

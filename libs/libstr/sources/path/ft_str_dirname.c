/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_dirname.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/21 23:57:44 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include <limits.h>

char		*ft_str_dirname(char const *path)
{
	static char	ret[FT_PATH_MAX + 1];
	size_t		len;
	char		*p;

	ft_memset(ret, 0, FT_PATH_MAX);
	if (0 == path || 0 == *path || 0 == ft_strchr(path, '/'))
		return (ft_strcpy(ret, "."));
	len = ft_strnlen(path, FT_PATH_MAX);
	ft_strncpy(ret, path, len);
	p = ret + len - 1;
	while ('/' == *p)
	{
		if (ret == p)
			return (ret);
		*p-- = 0;
	}
	while (p >= ret && '/' != *p)
		--p;
	if (p < path)
		return (ft_strcpy(ret, "."));
	if (p == path)
		return (ft_strcpy(ret, "/"));
	*p = 0;
	return (ret);
}

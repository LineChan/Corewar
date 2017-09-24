/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_del.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/11 23:11:12 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/24 19:40:42 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_option.h"
#include <stdlib.h>

void	ft_option_del(t_option **ptr)
{
	if (0 != *ptr)
	{
		if (0 != (*ptr)->option_count)
			free((void *)(*ptr)->option_list);
		if (0 != (*ptr)->rule_count)
			free((void *)(*ptr)->rule_list);
		free((void *)*ptr);
		*ptr = 0;
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_find.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/11 23:11:12 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/24 20:42:29 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_option.h"

char		*ft_option_find(t_option *opt, char const *option_name)
{
	int	cmp;
	int	low;
	int mid;
	int high;

	low = 0;
	high = opt->option_count;
	while (low < high)
	{
		mid = (low + high) >> 1;
		cmp = ft_option_compare(option_name, opt->option_list[mid].name);
		if (0 == cmp)
			return (opt->option_list[mid].data);
		if (0 < cmp)
			low = mid + 1;
		else
			high = mid;
	}
	return (0);
}

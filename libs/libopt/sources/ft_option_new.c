/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/11 23:11:12 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/24 20:41:32 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_option.h"
#include <stdlib.h>

t_option	*ft_option_new(int argc, char **argv)
{
	t_option	*new;

	new = (t_option *)calloc(1, sizeof(t_option));
	new->argc = argc;
	new->argv = argv;
	return (new);
}

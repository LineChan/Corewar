/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_option_new.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/11 23:11:12 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/10/02 02:03:35 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_option.h"
#include "ft_string.h"

t_option	*ft_option_new(int argc, char **argv)
{
	t_option	*new;

	new = (t_option *)ft_calloc(1, sizeof(t_option));
	INIT_LIST_HEAD(new->option_head);
	INIT_LIST_HEAD(new->rule_head);
	new->argc = argc;
	new->argv = argv;
	return (new);
}

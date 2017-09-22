/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/22 08:30:03 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	t_string		*null0;
	t_list			*null1;
	t_ctype_flags	null2;

	if (DEBUG_MODE)
		fprintf(stderr, "DEBUG ON\n");
	else
		fprintf(stderr, "DEBUG OFF\n");
	(void)null0;
	(void)null1;
	null2 = 0;

	(void)argc;
	(void)argv;
	return (0);
}

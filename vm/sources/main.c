/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/22 20:03:27 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "op.h"
#include <stdio.h>

extern t_op		g_op_tab[17];

int main(int argc, char **argv)
{
	t_string		*null0;
	t_list			*null1;
	t_ctype_flags	null2;

	if (1 == argc)
	{
		fprintf(stderr, "Usage: %s <champion.cor> [...]\n", ft_strrchr(*argv, '/') + 1);
		return (EXIT_FAILURE);
	}
	printf("Test: [%s]\n", g_op_tab[1].name);
	while (0 != --argc && 0 != *++argv)
	{
		printf("Arg: [%d]: [%s]\n", argc, *argv);
	}
	if (DEBUG_MODE)
		fprintf(stderr, "DEBUG ON\n");
	else
		fprintf(stderr, "DEBUG OFF\n");
	(void)null0;
	(void)null1;
	null2 = 0;

	(void)argc;
	(void)argv;
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/11/16 21:01:51 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_disass.h"
#include "ft_printf.h"

static void	ft_exec(char const *file_in)
{
	t_disass	dsm;

	if (EXIT_FAILURE == ft_disass_init(&dsm, file_in))
	{
		ft_disass_del(&dsm);
		return ;
	}
	ft_disass(&dsm);
	ft_disass_label(&dsm);
	ft_disass_gen(&dsm);
	ft_printf("Disassembler:   %f\n", ft_timer_diff(&dsm.benchmark[0]));
	ft_printf("Label Builder:  %f\n", ft_timer_diff(&dsm.benchmark[1]));
	ft_printf("Code generator: %f\n", ft_timer_diff(&dsm.benchmark[2]));
	ft_disass_del(&dsm);
	ft_printf("SUCCESS\n");
}

int			main(int argc, char **argv)
{
	if (2 > argc)
	{
		ft_printf("Usage: \"%s <champion.cor> [<champion.cor>]\"\n", argv[0]);
		return (0);
	}
	while (0 != *++argv)
		ft_exec(*argv);
	return (0);
}

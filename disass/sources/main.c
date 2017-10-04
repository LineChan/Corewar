/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/10/04 08:37:17 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_disass.h"
#include "ft_printf.h"

int			main(int argc, char **argv)
{
	t_disass	dsm;

	if (EXIT_FAILURE == ft_disass_init(&dsm, argc, argv))
	{
		ft_disass_del(&dsm);
		return (EXIT_FAILURE);
	}
	ft_disass(&dsm);
	ft_disass_label(&dsm);
	ft_disass_gen(&dsm);
	if (0 != ft_option_find(dsm.opt, "--benchmark"))
	{
		ft_printf("Disassembler:   %f\n", ft_timer_diff(&dsm.benchmark[0]));
		ft_printf("Label Builder:  %f\n", ft_timer_diff(&dsm.benchmark[1]));
		ft_printf("Code generator: %f\n", ft_timer_diff(&dsm.benchmark[2]));
	}
	ft_disass_del(&dsm);
	ft_printf("SUCCESS\n");
	return (EXIT_SUCCESS);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/09/30 17:20:52 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"
#include "ft_option.h"
#include "ft_printf.h"

int main(int argc, char **argv)
{
	t_option	*opt;

	if (DEBUG_MODE)
		ft_fprintf(ft_stderr, "DEBUG ON\n");
	else
		ft_fprintf(ft_stderr, "DEBUG OFF\n");
	opt = ft_option_new(argc, argv);
	ft_option_add_rule(opt, "--help", OPTION_KEY_BOOL);
	ft_option_parse(opt);
	if (0 != ft_option_find(opt, "--help"))
		ft_fprintf(ft_stdout, "Usage: %s [--help]\n", argv[0]);
	ft_option_del(&opt);
	return (EXIT_SUCCESS);
}

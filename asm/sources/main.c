/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/10/03 22:13:20 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_asm.h"
#include "ft_option.h"
#include "ft_printf.h"

/*
#include "instruction.h"
#include "ft_string.h"
#include "ft_ctype.h"

static int		ft_split(int c)
{
	return (ft_isspace(c) || ',' == c);
}

void	ft_test_instruction_encode(char const *line)
{
	t_instr *enc;
	char 	**tab;
	char	**p;

	p = tab = ft_strsplit(line, &ft_split);
	while (0 != *p)
		++p;
	enc = ft_instruction_encode(p - tab, tab);
	p = tab;
	while (0 != *p)
	{
		++p;
		free(p[-1]);
	}
	free(tab);
}
*/

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
	/*
	ft_test_instruction_encode("live %4");
	ft_test_instruction_encode("live %:l_0");
	ft_test_instruction_encode("add  r1,  r2, r3");
	ft_test_instruction_encode("st   r16, -490");
	*/
	ft_option_del(&opt);
	return (EXIT_SUCCESS);
}

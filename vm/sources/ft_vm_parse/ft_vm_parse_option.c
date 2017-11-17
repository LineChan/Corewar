/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_parse_option.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 17:01:00 by mvillemi          #+#    #+#             */
/*   Updated: 2017/11/17 17:05:24 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include <fcntl.h>

/*
* brief           Parse options from arguments
*
* param option    Options array
* param ac        Number of arguments
* param av        Arguments list
*/

t_option    *ft_vm_parse_option(int option[], int ac, char **av)
{
	char        **tmp;
	t_option    *opt;

	ft_memset((void *)option, '\0', sizeof(int) * OPTION_MAX);
	/* Allocation an options' structure */
	opt = ft_option_new(ac, av);
	/* Add every rule needed*/
	ft_option_add_rule(opt, "-dump", OPTION_KEY_STRING);
	ft_option_add_rule(opt, "-summary", OPTION_KEY_BOOL);
	// TODO : every option
	ft_option_add_rule(opt, "--help", OPTION_KEY_BOOL);
	ft_option_add_rule(opt, "-a", OPTION_KEY_STRING);
	ft_option_add_rule(opt, "-ctmo", OPTION_KEY_STRING);
	ft_option_parse(opt);
	if (ft_option_find(opt, "--help"))
		ft_fprintf(ft_stdout, "Usage: %s [--help]\n", *av);
	if ((tmp = ft_option_find(opt, "-dump")))
		option[0] = ft_atoi(*tmp);
	if (ft_option_find(opt, "-summary"))
	{
		option[5] = open("summary.txt", O_CREAT | O_RDWR | O_TRUNC, 0666);
		// FD = open("input.txt", O_CREAT | O_RDWR | O_TRUNC, 0666);
		if (IS_NEG(option[5]))
			EXIT_FAIL("Error : Wrong File Descriptor for the Summary");
	}
	return (opt);
}

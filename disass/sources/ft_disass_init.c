/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_disass_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/15 11:17:11 by Zoellingam        #+#    #+#             */
/*   Updated: 2017/10/04 08:37:39 by Zoellingam       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_disass.h"
#include "ft_printf.h"
#include <unistd.h>
#include <fcntl.h>

static int	ft_usage(void)
{
	ft_fprintf(ft_stdout, "Usage: ./disass\n");
	ft_fprintf(ft_stdout, "\t--source\tSource file\n");
	ft_fprintf(ft_stdout, "\t--dest\t\tDestination file\n");
	ft_fprintf(ft_stdout, "\t--benchmark\tDisplay benchmark on stdout\n");
	ft_fprintf(ft_stdout, "\t--help\t\tDisplay usage and quit\n\n");
	ft_fprintf(ft_stdout, "Example:\n\t./disass --source=file.cor ");
	ft_fprintf(ft_stdout, "--benchmark --dest file.s\n");
	return (EXIT_FAILURE);
}

static int	ft_init_stream(t_disass *dsm)
{
	char	*file;
	int		norme;

	if (0 != ft_option_find(dsm->opt, "--help"))
		return (ft_usage());
	norme = O_WRONLY | O_CREAT;
	if (0 != (file = ft_option_find(dsm->opt, "--source")))
		if (-1 != (dsm->fd_in = open(file, O_RDONLY)))
			if (0 != (file = ft_option_find(dsm->opt, "--dest")))
				if (-1 == access(file, F_OK))
					if (-1 != (dsm->fd_out = open(file, norme, 0644)))
						return (EXIT_SUCCESS);
					else
						ft_fprintf(ft_stderr, "Can't open dest file\n");
				else
					ft_fprintf(ft_stderr, "Destination file already exist\n");
			else
				ft_fprintf(ft_stderr, "Option[\"--dest\"] is missing\n");
		else
			ft_fprintf(ft_stderr, "Can't open source file\n");
	else
		ft_fprintf(ft_stderr, "Option[\"--source\"] is missing\n");
	return (EXIT_FAILURE);
}

int			ft_disass_init(t_disass *dsm, int argc, char **argv)
{
	/* Init lists */
	INIT_LIST_HEAD(dsm->instr_head);
	INIT_LIST_HEAD(dsm->label_head);
	/* Create new option instance */
	dsm->opt = ft_option_new(argc, argv);
	ft_option_add_rule(dsm->opt, "--help", OPTION_KEY_BOOL);
	ft_option_add_rule(dsm->opt, "--benchmark", OPTION_KEY_BOOL);
	ft_option_add_rule(dsm->opt, "--dest", OPTION_KEY_STRING);
	ft_option_add_rule(dsm->opt, "--source", OPTION_KEY_STRING);
	/* Parse argc/argv  */
	ft_option_parse(dsm->opt);
	/* Check for input/ouput files */
	return (ft_init_stream(dsm));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_parse_option.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 17:01:00 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/22 17:02:17 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

/**
 * \fn t_option *ft_vm_option (int option[], int ac, char **av)
 * \brief Parse options
 *
 * \param option
 * \param number of arguments
 * \param arguments' list
 * \return options' structure
 */

t_option    *ft_vm_parse_option(int option[], int ac, char **av)
{
  char        **tmp;
  t_option    *opt;

  ft_memset((void *)option, '\0', sizeof(int) * OPTION_MAX);
  opt = ft_option_new(ac, av);
  ft_option_add_rule(opt, "--help", OPTION_KEY_BOOL);
  ft_option_add_rule(opt, "-dump", OPTION_KEY_STRING);
  // TODO: option -a
  ft_option_add_rule(opt, "-a", OPTION_KEY_STRING);
  // TODO: option -ctmo
  ft_option_add_rule(opt, "-ctmo", OPTION_KEY_STRING);
  ft_option_parse(opt);
  // TODO: --help
  if (ft_option_find(opt, "--help"))
    ft_fprintf(ft_stdout, "Usage: %s [--help]\n", *av);
  if ((tmp = ft_option_find(opt, "-dump")))
    option[0] = ft_atoi(*tmp);

return (opt);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_option.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 00:47:55 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/21 18:23:31 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"

t_option    *ft_vm_option(int option[], int ac, char **av)
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

#if 0
  {
    int i = 0;
    while (tmp[i])
    {
      ft_printf("tmp[%d] : '%s'\n", i, tmp[i]);
      ++i;
    }
    tmp[0] ? option[1] = ft_atoi(tmp[0]);
    option[1] = tmp
    option[2] = ft_atoi(tmp[1]);
    option[3] = ft_atoi(tmp[2]);
    option[4] = ft_atoi(tmp[3]);
  }
  #endif

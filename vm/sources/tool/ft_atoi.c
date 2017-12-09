/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 00:46:50 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/09 15:29:41 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"
#include "ft_ctype.h"
#include "macro.h"

int          ft_atoi(char *str)
{
  int           sign;
  long int        nb;

  nb = 0;
  sign = 1;
  if (*str == '-')
	  sign = -1;
  if ((*str == '-') || (*str == '+'))
	  ++str;
  while (ft_isdigit(*str))
  {
    nb = (nb << 3) + (nb << 1) + *str++ - 48;
    ASSERT((nb > 2147483647) || ((nb > 2147483648) && IS_NEG(sign)));
  }
  ASSERT(*str);
  return (IS_NEG(sign) ? -nb : nb);
}

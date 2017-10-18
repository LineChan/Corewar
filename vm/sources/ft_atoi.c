/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/19 00:46:50 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/19 01:12:06 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_vm.h"

int          ft_atoi(char *str)
{
  int             sign;
  unsigned int    nb;

  nb = 0;
  sign = 1;
  if (*str == '-')
    sign = -1;
  if ((*str == '-') || (*str == '+'))
    ++str;
  while (ft_isdigit(*str))
    nb = (nb << 3) + (nb << 1) + *str++ - 48;
  if ((!ft_isspace(*str)) && ((*str != 0) ||
      ((nb > 2147483647) || ((nb > 2147483648) && IS_NEG(sign)))))
      EXIT_FAIL("Error : not an integer");
  return (IS_NEG(sign) ? -nb : nb);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vm_read_champion.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 17:28:43 by mvillemi          #+#    #+#             */
/*   Updated: 2017/10/21 18:23:48 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ft_vm.h"
# include <unistd.h>

static void ft_vm_check_magic(int option[], t_header *header)
{
  int   i;

  i = 1;
  // TODO : convert Little endian or not
  while (i < OPTION_MAX)
  {
    if (option[i])
    {
      ft_printf("option[%d] : FD = %d\n", i, option[i]);
      if ((IS_NEG(read(option[i], &header->magic, sizeof(header->magic)))))
        EXIT_FAIL("Error : wrong magic number")
        // TODO: check if magic number is ok
      ft_printf("Ma")
    }
    ++i;
  }

}
void ft_vm_read_champion(int option[], t_header *header)
{
  ft_vm_check_magic(option, header);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assert.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvillemi <mvillemi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 14:11:40 by mvillemi          #+#    #+#             */
/*   Updated: 2017/12/09 15:20:10 by mvillemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_vm.h"
#include "ft_printf.h"

void			ft_assert(char const *condition,
						  char const *function_name,
						  int const line_number,
						  const int code_condition)
{
	if (0 == code_condition)
	{
		ft_printf("%s(%d): assert(%s)\n", function_name, line_number, condition);
		exit(1);
	}
}

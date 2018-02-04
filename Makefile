# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igomez <igomez@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/30 20:03:48 by igomez            #+#    #+#              #
#*   Updated: 2018/02/04 15:43:42 by mvillemi         ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

ifndef CUR_PROJECT_PWD
 export CUR_PROJECT_PWD := $(shell /bin/pwd)
endif

LIB		:= "libft"
VM_DIR  := "vm"
ASM_DIR := "asm"
DSM_DIR := "disass"

all:
	@make -C $(LIB);
	@make -C $(ASM_DIR);
	@make -C $(DSM_DIR);
	@make -C $(VM_DIR);

clean:
	@make -C $(LIB) clean;
	@make -C $(ASM_DIR) clean;
	@make -C $(DSM_DIR) clean;
	@make -C $(VM_DIR) clean;

fclean:
	#@make -C $(LIB) fclean;
	@make -C $(ASM_DIR) fclean;
	@make -C $(DSM_DIR) fclean;
	@make -C $(VM_DIR) fclean;
	@rm -rf "docs/html";

re: fclean all

.PHONY: all clean fclean re
.SILENT:

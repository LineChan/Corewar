# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: Zoellingam <illan91@hotmail.com>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/30 20:03:48 by igomez            #+#    #+#              #
#    Updated: 2017/09/24 21:06:30 by Zoellingam       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef CUR_PROJECT_PWD
 export CUR_PROJECT_PWD := $(shell /bin/pwd)
endif

VM_DIR  := "vm"
ASM_DIR := "asm"
DSM_DIR := "disass"

all:
	@make -C $(ASM_DIR);
	@make -C $(DSM_DIR);
	@make -C $(VM_DIR);

clean:
	@make -C $(VM_DIR) clean;
	@make -C $(ASM_DIR) clean;
	@make -C $(DSM_DIR) clean;

fclean:
	@make -C $(VM_DIR) fclean;
	@make -C $(ASM_DIR) fclean;
	@make -C $(DSM_DIR) fclean;

debug:
	@make DEBUG=1 -C $(VM_DIR);
	@make DEBUG=1 -C $(ASM_DIR);
	@make DEBUG=1 -C $(DSM_DIR);

asm:
	@make -C $(ASM_DIR);

vm:
	@make -C $(VM_DIR);

disass:
	@make -C $(DSM_DIR)


re: fclean all

doxygen: fclean
	@doxygen "Doxyfile"

doxyclean:
	@rm -rf "html" "man" "latex" 2> /dev/null

allclean: doxyclean fclean

-include $(DEPS)

.PHONY: all clean fclean re doxygen doxyclean allclean asm vm disass debug
.SILENT:

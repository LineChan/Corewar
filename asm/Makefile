# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: igomez <igomez@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/09/30 20:03:48 by igomez            #+#    #+#              #
#    Updated: 2018/02/04 14:50:25 by igomez           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifndef CUR_PROJECT_PWD
 export CUR_PROJECT_PWD := $(shell /bin/pwd)
endif

NAME 			:= asm

INCS 			:= includes
SRCS 			:= sources
DLIB 			:= $(CUR_PROJECT_PWD)/libft
COMN			:= $(CUR_PROJECT_PWD)/common
OBJS 			:= objs

INCLUDES 		:= -I$(COMN) -I$(INCS) -I$(DLIB)/$(INCS)

LIBS			:= -lncurses -L $(DLIB) -lft

# Search source files
C_FILES			:= $(shell find $(SRCS) -type f)
C_FILES			+= $(shell find $(COMN) -type f -name "*.c")
C_DIRS		 	:= $(shell find $(SRCS) -type d)
C_DIRS			+= $(COMN)

# Add to C_FLAGS
ifeq ($(DEBUG),1)
C_FLAGS		 	:= -MMD -g -DDEBUG -Wall -Wextra -Werror -std=c89 -pedantic
else
C_FLAGS		 	:= -MMD -g -Wall -Wextra -Werror -std=c89 -pedantic
endif

# Build .o files
O_DIRS			:= $(addprefix $(OBJS)/,$(C_DIRS))
O_FILES			:= $(C_FILES:%.c=$(OBJS)/%.o)

# Create OBJS and childs
$(shell mkdir -p $(O_DIRS) $(OBJS))

DEPS 			:= $(O_FILES:.o=.d)

# Print
ACTUAL = $(words $(COUNT))
TOTAL  = $(words $(filter %.c,$(C_FILES)))
CALCUL = $(shell echo $(ACTUAL)\*100\/$(TOTAL) | bc)
PYTHON = $(shell python -c "print '%-10s' % ('I'*($(CALCUL)/10))")
SIZE   := $(shell echo "$(shell tput cols) - 32" | bc)

PRINT_RED   = printf " [\033[31;1m%s\033[0m]\033[31;1m\t%3s%%\033[0m\t-->>\t\033[31;1m%-*s\033[0m\r" "$(PYTHON)" "$(CALCUL)" "$(SIZE)"
PRINT_GREEN = printf " [\033[32;1m%s\033[0m]\033[32;1m\t%3s%%\033[0m\t-->>\t\033[32;1m%-*s\033[0m\n" "    Ok!   " "100" "$(SIZE)"

all:
	@make $(NAME)

$(NAME): $(O_FILES)
	@gcc $(C_FLAGS) $(INCLUDES) $(LIBS) -o $@ $(O_FILES) && $(PRINT_GREEN) $@ || exit

$(OBJS)/%.o: %.c
	@gcc $(C_FLAGS) $(INCLUDES) -o $@ -c $< && $(eval COUNT+=1) $(PRINT_RED) $< || exit

clean:
	@rm -rf $(O_FILES) $(OBJS) 2> /dev/null

fclean: clean
	@rm -f "$(NAME)"

re: fclean all

doxygen: fclean
	@doxygen "Doxyfile"

doxyclean:
	@rm -rf "html" "man" "latex" 2> /dev/null

allclean: doxyclean fclean

-include $(DEPS)

.PHONY: all clean fclean re doxygen doxyclean allclean
.SILENT:

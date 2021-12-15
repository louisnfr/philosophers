# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 14:21:00 by lraffin           #+#    #+#              #
#    Updated: 2021/12/15 18:24:25 by lraffin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

### EXECUTABLE ###
NAME	= philo

### SOURCE FILES ###
SOURCES = \
		main.c \
		init.c \
		exit.c \
		routine.c \
		\
		utils/ft_strlen.c \
		utils/ft_putstr_fd.c \
		utils/gettime.c \
		utils/ft_atoi.c

### COMPILATION ###
CC		= clang
CFLAGS	= -Wall -Wextra -Werror -MMD -MP -I$(INCLUDE)
DEBUG_F	= -g3 -fsanitize=address
LIBS	= -pthread

### INCLUDES ###
INCLUDE		= inc
SRC_PATH	= src
OBJ_PATH	= obj

### OBJECTS ###
SRC	= $(addprefix $(SRC_PATH)/,$(SOURCES))
OBJ	= $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.o))
DEP	= $(addprefix $(OBJ_PATH)/,$(SOURCES:.c=.d))

### COLORS ###
NOC		= \033[0m
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
WHITE	= \033[1;37m

### RULES ###

all:
	@make -s $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBS)
	@echo "$(GREEN)$@$(NOC)"

-include $(DEP)
$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c $(INCLUDE)/$(NAME).h
	@mkdir -p obj/utils
	@$(CC) $(CFLAGS) -c -o $@ $<
	@echo "$(BLUE)clang $(NOC)$(notdir $@)"


clean:
	@echo "$(RED)clean$(NOC)"
	@rm -rf $(OBJ_PATH)

fclean: clean
	@echo "$(RED)fclean$(NOC)"
	@rm -f $(NAME)

re: fclean all

norm:
	-@norminette $(SRC_PATH)
	-@norminette $(INCLUDE)

push:
	git add .
	git status
	git commit -m philosophers
	git push

.PHONY:	all clean fclean re debug norm push

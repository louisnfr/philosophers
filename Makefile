# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 14:21:00 by lraffin           #+#    #+#              #
#    Updated: 2021/12/16 02:28:17 by lraffin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

SRCS =				\
		main.c		\
		$(ROUTINE)	\
		$(INIT)		\
		$(EXIT)		\
		$(UTILS)

INIT =					\
		init.c			\
		create_philos.c

ROUTINE =			\
		routine.c	\
		actions.c

EXIT =			\
		exit.c

UTILS =					\
		utils.c			\
		gettime.c		\
		check_death.c		\
		update_status.c

OBJS	= $(SRCS:%.c=$(OBJ_DIR)/%.o)
DEPS	= $(OBJS:%.o=%.d)

INC_DIR	= inc
SRC_DIR	= src
OBJ_DIR	= obj

CC		= clang
CFLAGS	= -Wall -Wextra -Werror -MMD -MP
LDFLAGS	= -pthread
DEBUG	= -g3 -fsanitize=address

vpath %.c $(addprefix $(SRC_DIR)/, . init routine exit utils)

all: $(NAME)

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)
	@echo "$(GREEN)$@$(NOC)"

-include $(DEPS)
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I$(INC_DIR) -c $< -o $@
	@echo "$(BLUE)clang $(NOC)$(notdir $@)"

clean:
	@echo "$(RED)clean$(NOC)"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(RED)fclean$(NOC)"
	@rm -f $(NAME)

re: fclean all

norm:
	@echo "$(YELLOW)SOURCES$(NOC)"
	-@norminette $(SRC_DIR)
	@echo "$(YELLOW)INCLUDES$(NOC)"
	-@norminette $(INC_DIR)

push:
	git add .
	git status
	git commit -m philosophers
	git push

.PHONY:	all clean fclean re debug norm push

NOC		= \033[0m
RED		= \033[1;31m
GREEN	= \033[1;32m
YELLOW	= \033[1;33m
BLUE	= \033[1;34m
WHITE	= \033[1;37m

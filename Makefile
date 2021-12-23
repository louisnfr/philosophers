# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lraffin <lraffin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/15 14:21:00 by lraffin           #+#    #+#              #
#    Updated: 2021/12/23 18:31:42 by lraffin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo

SRCS =				\
		main.c		\
		$(ROUTINE)	\
		$(PARSING)	\
		$(INIT)		\
		$(EXIT)		\
		$(UTILS)

INIT =					\
		data.c			\
		philos.c

PARSING =				\
		input.c

ROUTINE =				\
		routine.c		\
		eat.c

EXIT =					\
		exit.c			\
		clean_data.c

UTILS =					\
		utils.c			\
		mutex.c			\
		time.c			\
		print.c

OBJS	= $(SRCS:%.c=$(OBJ_DIR)/%.o)
DEPS	= $(OBJS:%.o=%.d)

INC_DIR	= inc
SRC_DIR	= src
OBJ_DIR	= obj

CC		= clang
CFLAGS	= -Wall -Wextra -Werror -MMD -MP -g3 #$(DEBUG)
LDFLAGS	= -pthread
DEBUG	= -g3 -fsanitize=thread

vpath %.c $(addprefix $(SRC_DIR)/, . init parsing routine exit utils)

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

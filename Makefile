# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nleggeri <nleggeri@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/10 11:10:16 by nleggeri          #+#    #+#              #
#    Updated: 2023/03/30 12:35:57 by nleggeri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VARIABLES
NAME 			= minishell
CC				= gcc
FLAGS 			= -Wall -Werror -Wextra -g
SANITIZE		= -fsanitize=address

# OBJ
OBJS_DIR   		= objs
OBJS 			= $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)

# SOURCES
SRCS_DIR   		= srcs
SIGNALS_DIR		= signals
CLOSE_DIR		= close
SRCS 			= $(wildcard $(SRCS_DIR)/*.c) \
				  $(wildcard $(SRCS_DIR)/$(SIGNALS_DIR)/*.c) \
				  $(wildcard $(SRCS_DIR)/$(CLOSE_DIR)/*.c)

# COLORS
_END=$'\x1b[0m'
_SUCCESS=$'\x1b[42m'
_CLEANED=$'\x1b[44m'

# COMMANDS
all:			$(OBJS_DIR) $(NAME)
				@echo "$(_SUCCESS)🚀Build All!$(_END)"

$(NAME): 		$(OBJS)
				make -C libft
				$(CC) $(FLAGS) $(OBJS) libft/libft.a -o $(NAME) -lreadline -L /opt/homebrew/opt/readline/lib -I /opt/homebrew/opt/readline/include
				@echo "$(_SUCCESS)🚀Build!$(_END)"

$(OBJS_DIR):
				mkdir -p $(OBJS_DIR)
				mkdir -p $(OBJS_DIR)/$(SIGNALS_DIR)
				mkdir -p $(OBJS_DIR)/$(CLOSE_DIR)

$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c
				$(CC) $(FLAGS) -c $< -o $@

clean:
				make clean -C libft
				/bin/rm -rf $(OBJS_DIR)
				@echo "$(_CLEANED)🧹Clean object files!$(_END)"

fclean: 		clean
				make fclean -C libft
				/bin/rm -rf $(NAME)
				@echo "$(_CLEANED)🧹Clean executable files!$(_END)"

re: 			fclean all
				@echo "$(_SUCCESS)🧹Clean + 🚀Build!$(_END)"

check:
				bash checker.sh

.PHONY:			all clean fclean re check
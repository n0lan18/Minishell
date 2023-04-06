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
OBJS			= $(SRC:.c=.o)

# SOURCES
SRC				= srcs/main.c \
                  srcs/readline_to_tab.c \
                  srcs/check_words_in_tab.c \
                  srcs/search_cmd.c \
                  srcs/free_fonctions.c \

# COLORS
_END=$'\x1b[0m'
_SUCCESS=$'\x1b[42m'
_CLEANED=$'\x1b[44m'

# COMMANDS
all:			$(NAME)
				@echo "$(_SUCCESS)🚀Build All!$(_END)"

$(NAME): 		$(OBJS)
				make -C libft
				$(CC) $(FLAGS) $(OBJS) libft/libft.a -o $(NAME) -lreadline
				@echo "$(_SUCCESS)🚀Build!$(_END)"

%.o: %.c
				$(CC) $(FLAGS) -c $< -o $@

clean:
				make clean -C libft
				/bin/rm -rf $(OBJS)
				@echo "$(_CLEANED)🧹Clean object files!$(_END)"

fclean: 		clean
				make fclean -C libft
				/bin/rm -rf $(NAME)
				@echo "$(_CLEANED)🧹Clean executable files!$(_END)"

re: 			fclean all
				@echo "$(_SUCCESS)🧹Clean + 🚀Build!$(_END)"

.PHONY:			all clean fclean re
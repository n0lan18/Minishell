# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nleggeri <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/25` 12:34:25 by nleggeri          #+#    #+#              #
#    Updated: 2023/01/17 14:02:16 by nleggeri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= libft.a

SOURCES	= \
			ft_isalpha.c ft_memchr.c  ft_memset.c  ft_strlen.c  ft_tolower.c \
			ft_atoi.c    ft_isascii.c ft_memcmp.c  ft_strchr.c  ft_strncmp.c ft_toupper.c \
			ft_bzero.c   ft_isdigit.c ft_memcpy.c  ft_strlcat.c ft_strnstr.c ft_memchr.c \
			ft_isalnum.c ft_isprint.c ft_memmove.c ft_strlcpy.c ft_strrchr.c ft_calloc.c \
			ft_strdup.c ft_substr.c ft_strjoin.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c \
			ft_putendl_fd.c ft_putnbr_fd.c ft_striteri.c ft_strtrim.c ft_itoa.c ft_split.c \
			get_next_line.c ft_printf.c percent_c.c percent_d.c percent_p.c percent_s.c \
			percent_u.c percent_xx.c \
						
OBJS	= $(SOURCES:.c=.o)

CC	= gcc

CFLAGS	= -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) -r $@ $?

%.o: %.c
	$(CC) -c $(CFLAGS) $?

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re

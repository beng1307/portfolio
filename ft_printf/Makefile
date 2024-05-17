# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/08 12:02:48 by bgretic           #+#    #+#              #
#    Updated: 2024/05/17 14:48:51 by bgretic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = libft/ft_atoi.c libft/ft_isalpha.c libft/ft_memchr.c libft/ft_memset.c libft/ft_strlcpy.c libft/ft_strrchr.c \
libft/ft_bzero.c libft/ft_isascii.c libft/ft_memcmp.c libft/ft_strchr.c libft/ft_strlen.c libft/ft_tolower.c \
libft/ft_calloc.c libft/ft_isdigit.c libft/ft_memcpy.c libft/ft_strdup.c libft/ft_strncmp.c libft/ft_toupper.c \
libft/ft_isalnum.c libft/ft_isprint.c libft/ft_memmove.c libft/ft_strlcat.c	libft/ft_strnstr.c libft/ft_substr.c \
libft/ft_strjoin.c libft/ft_strtrim.c libft/ft_itoa.c libft/ft_strmapi.c libft/ft_striteri.c libft/ft_putchar_fd.c \
libft/ft_putstr_fd.c libft/ft_putendl_fd.c libft/ft_putnbr_fd.c libft/ft_split.c ft_print_cs.c  ft_print_diu.c \
ft_printf.c  ft_print_xXp.c 
OBJS = $(SRCS:.c=.o)
FROM = -I . -I ./libft
LIB = ar rcs

all: $(NAME)

$(NAME): $(OBJS)
	$(LIB) $(NAME) $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) $(FROM) -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

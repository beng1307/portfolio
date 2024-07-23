# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/26 12:32:52 by bgretic           #+#    #+#              #
#    Updated: 2024/07/20 18:46:26 by bgretic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -g -Wall -Werror -Wextra
SRCS =	libft/ft_atoi.c \
		libft/ft_isalpha.c \
		libft/ft_memchr.c \
		libft/ft_memset.c \
		libft/ft_strlcpy.c \
		libft/ft_strrchr.c \
		libft/ft_bzero.c \
		libft/ft_isascii.c \
		libft/ft_memcmp.c \
		libft/ft_strchr.c \
		libft/ft_strlen.c \
		libft/ft_tolower.c \
		libft/ft_calloc.c \
		libft/ft_isdigit.c \
		libft/ft_memcpy.c \
		libft/ft_strdup.c \
		libft/ft_strncmp.c \
		libft/ft_toupper.c \
		libft/ft_isalnum.c \
		libft/ft_isprint.c \
		libft/ft_memmove.c \
		libft/ft_strlcat.c \
		libft/ft_strnstr.c \
		libft/ft_substr.c \
		libft/ft_strjoin.c \
		libft/ft_strtrim.c \
		libft/ft_itoa.c \
		libft/ft_strmapi.c \
		libft/ft_striteri.c \
		libft/ft_putchar_fd.c \
		libft/ft_putstr_fd.c \
		libft/ft_putendl_fd.c \
		libft/ft_putnbr_fd.c \
		libft/ft_split.c \
		libft/ft_printf.c \
		libft/ft_printf/ft_print_cs.c \
		libft/ft_printf/ft_print_diu.c \
		libft/ft_printf/ft_print_xXp.c \
		libft/ft_lstadd_back.c \
		libft/ft_lstadd_front.c \
		libft/ft_lstclear.c \
		libft/ft_lstdelone.c \
		libft/ft_lstlast.c \
		libft/ft_lstnew.c \
		libft/ft_lstsize.c \
		ft_push.c \
		ft_rotate.c \
		ft_rev_rotate.c \
		ft_swap.c \
		is_sorted.c \
		my_sort.c \
		get_values.c \
		move_counter.c \
		sorting_logic.c \
		create_list.c \
		error_handling.c \
		ps_lstnew.c \
		small_sort.c \
		sort_5.c \
		main.c
OBJS = $(SRCS:.c=.o)
FROM = -I libft

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(FROM) $(OBJS) -o $@

%.o: %.c
	$(CC) $(CFLAGS) $(FROM) -o $@ -c $<

clean:
	rm -f $(OBJS)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

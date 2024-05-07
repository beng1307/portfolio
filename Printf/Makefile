NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Werror -Wextra
SRCS = Libft/ft_atoi.c Libft/ft_isalpha.c Libft/ft_memchr.c Libft/ft_memset.c Libft/ft_strlcpy.c Libft/ft_strrchr.c \
Libft/ft_bzero.c Libft/ft_isascii.c Libft/ft_memcmp.c Libft/ft_strchr.c Libft/ft_strlen.c Libft/ft_tolower.c \
Libft/ft_calloc.c Libft/ft_isdigit.c Libft/ft_memcpy.c Libft/ft_strdup.c Libft/ft_strncmp.c Libft/ft_toupper.c \
Libft/ft_isalnum.c Libft/ft_isprint.c Libft/ft_memmove.c Libft/ft_strlcat.c	Libft/ft_strnstr.c Libft/ft_substr.c \
Libft/ft_strjoin.c Libft/ft_strtrim.c Libft/ft_itoa.c Libft/ft_strmapi.c Libft/ft_striteri.c Libft/ft_putchar_fd.c \
Libft/ft_putstr_fd.c Libft/ft_putendl_fd.c Libft/ft_putnbr_fd.c Libft/ft_split.c ft_print_cs.c  ft_print_diu.c \
ft_printf.c  ft_print_xXp.c  ft_utoa.c 
OBJS = $(SRCS:.c=.o)
FROM = -I Libft
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

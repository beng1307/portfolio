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

#for compiling
COMPILE = cc -Wall -Werror -Wextra


#make libft.a
LIBFT = libft/libft.a

LIBFT_H = -I libft

$(LIBFT):
	cd libft && make all


#fractol
FRACTOL = fractol

FRACTOL_SRCS = main.c

FRACTOL_OBJS = $(FRACTOL_SRCS:.c=.o)

$(FRACTOL): $(FRACTOL_OBJS) $(LIBFT)
	$(COMPILE) $(FRACTOL_OBJS) $(LIBFT) $(LIBFT_H) -o $(FRACTOL)


#anti-relink
%.o: %.c
	$(COMPILE) -c $< -o $@


#commands
all: $(FRACTOL)

clean:
	@rm -f $(FRACTOL_OBJS)
	@cd libft && make clean

fclean:	clean
	@rm -f $(FRACTOL)
	@cd libft && make fclean

re: fclean all

.PHONY: all clean fclean re

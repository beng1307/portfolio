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


#So_Long
SO_LONG = SO_LONG

SO_LONG_SRCS = main.c

SO_LONG_OBJS = $(SO_LONG_SRCS:.c=.o)

$(SO_LONG): $(SO_LONG_OBJS) $(LIBFT)
	$(COMPILE) $(SO_LONG_OBJS) $(LIBFT) $(LIBFT_H) -o $(SO_LONG)


#anti-relink
%.o: %.c
	$(COMPILE) -c $< -o $@


#commands
all: $(SO_LONG)

clean:
	@rm -f $(SO_LONG_OBJS)
	@cd libft && make clean

fclean:	clean
	@rm -f $(SO_LONG)
	@cd libft && make fclean

re: fclean all

.PHONY: all clean fclean re

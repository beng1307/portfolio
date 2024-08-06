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
COMPILE = cc -g -Wall -Werror -Wextra


#make libft.a
LIBFT = libft/libft.a

LIBFT_H = -I libft

$(LIBFT):
	cd libft && make all


#server
SERVER = server

SERVER_SRCS = ft_server.c

SERVER_OBJS = $(SERVER_SRCS:.c=.o)

$(SERVER): $(SERVER_OBJS) $(LIBFT)
	$(COMPILE) $(SERVER_OBJS) $(LIBFT) $(LIBFT_H) -o $(SERVER)


#client
CLIENT = client

CLIENT_SRCS = ft_client.c

CLIENT_OBJS = $(CLIENT_SRCS:.c=.o)

$(CLIENT): $(CLIENT_OBJS) $(LIBFT)
	$(COMPILE) $(CLIENT_OBJS) $(LIBFT) $(LIBFT_H) -o $(CLIENT)


#anti-relink
%.o: %.c
	$(COMPILE) -c $< -o $@


#commands
all: $(SERVER) $(CLIENT)

clean:
	@rm -f $(SERVER_OBJS) $(CLIENT_OBJS)
	@cd libft && make clean

fclean:	clean
	@rm -f $(SERVER) $(CLIENT)
	@cd libft && make fclean

re: fclean all

.PHONY: all clean fclean re

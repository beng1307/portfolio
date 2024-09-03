# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/26 12:32:52 by bgretic           #+#    #+#              #
#    Updated: 2024/08/26 18:12:30 by bgretic          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# #for compiling
# COMPILE = cc -g -Wall -Werror -Wextra


# #including mlx
# MLX = -lmlx -lXext -lX11


# #make libft.a
# LIBFT = libft/libft.a

# LIBFT_H = -I libft

# $(LIBFT):
# 	cd libft && make all


# #So_Long
# SO_LONG = so_long

# SO_LONG_SRCS = main.c all_collectibles_collected.c \
# check_path.c check_walls.c exit_game.c get_player_pos.c \
# handle_events.c handle_keys.c init_mlx_win.c init_sprites.c \
# is_the_map_complete.c open_door.c parse_and_check_map.c \
# put_background.c put_map_content.c


# SO_LONG_OBJS = $(SO_LONG_SRCS:.c=.o)

# $(SO_LONG): $(SO_LONG_OBJS) $(LIBFT)
# 	$(COMPILE) $(MLX) $(SO_LONG_OBJS) $(LIBFT) $(LIBFT_H) -o $(SO_LONG)


# #anti-relink
# %.o: %.c
# 	$(COMPILE) -c $< -o $@


# #commands
# all: $(SO_LONG)

# clean:
# 	@rm -f $(SO_LONG_OBJS)
# 	@cd libft && make clean

# fclean:	clean
# 	@rm -f $(SO_LONG)
# 	@cd libft && make fclean

# re: fclean all

# .PHONY: all clean fclean re

# Compiler and flags
CC = cc
CFLAGS = -g -Wall -Werror -Wextra -I minilibx-linux -I libft
LDFLAGS = -L minilibx-linux -lmlx -lXext -lX11 -lXrandr -lXft -lXinerama

# Library paths
LIBFT = libft/libft.a
MLX_A = minilibx-linux/libmlx_Linux.a

# Object files and sources
SO_LONG = so_long
SO_LONG_SRCS = main.c all_collectibles_collected.c \
check_path.c check_walls.c exit_game.c get_player_pos.c \
handle_events.c handle_keys.c init_mlx_win.c init_sprites.c \
is_the_map_complete.c open_door.c parse_and_check_map.c \
put_background.c put_map_content.c parse_map.c

SO_LONG_OBJS = $(SO_LONG_SRCS:.c=.o)

# Targets
$(LIBFT):
	cd libft && make all

$(SO_LONG): $(SO_LONG_OBJS) $(LIBFT) $(MLX_A)
	$(CC) $(CFLAGS) $(SO_LONG_OBJS) $(LIBFT) $(LDFLAGS) -o $(SO_LONG)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(SO_LONG)

clean:
	@rm -f $(SO_LONG_OBJS)
	@cd libft && make clean

fclean: clean
	@rm -f $(SO_LONG)
	@cd libft && make fclean

re: fclean all

.PHONY: all clean fclean re

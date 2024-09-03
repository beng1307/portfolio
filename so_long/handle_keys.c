#include "so_long.h"

void	move_up(t_mlx **game)
{
	if ((*game)->map[(*game)->p_pos->y - 1][(*game)->p_pos->x] != '1'
		&& (*game)->map[(*game)->p_pos->y - 1][(*game)->p_pos->x] != 'E')
	{
		(*game)->map[(*game)->p_pos->y - 1][(*game)->p_pos->x] = 'P';
		(*game)->map[(*game)->p_pos->y][(*game)->p_pos->x] = '0';
		(*game)->p_pos->y--;
		(*game)->moves++;
		ft_putnbr_fd((*game)->moves, 1);
	}
	else if ((*game)->map[(*game)->p_pos->y - 1][(*game)->p_pos->x] == 'E'
		&& (*game)->collected == true)
	{
		ft_putstr_fd("You won, thank you for playing!", 1);
		exit_game(game, NULL);
	}
}

void	move_down(t_mlx **game)
{
	if ((*game)->map[(*game)->p_pos->y + 1][(*game)->p_pos->x] != '1'
		&& (*game)->map[(*game)->p_pos->y + 1][(*game)->p_pos->x] != 'E')
	{
		(*game)->map[(*game)->p_pos->y + 1][(*game)->p_pos->x] = 'P';
		(*game)->map[(*game)->p_pos->y][(*game)->p_pos->x] = '0';
		(*game)->p_pos->y++;
		(*game)->moves++;
		ft_putnbr_fd((*game)->moves, 1);
	}
	else if ((*game)->map[(*game)->p_pos->y + 1][(*game)->p_pos->x] == 'E'
		&& (*game)->collected == true)
	{
		ft_putstr_fd("You won, thank you for playing!", 1);
		exit_game(game, NULL);
	}
}

void	move_left(t_mlx **game)
{
	if ((*game)->map[(*game)->p_pos->y][(*game)->p_pos->x - 1] != '1'
		&& (*game)->map[(*game)->p_pos->y][(*game)->p_pos->x - 1] != 'E')
	{
		(*game)->map[(*game)->p_pos->y][(*game)->p_pos->x - 1] = 'P';
		(*game)->map[(*game)->p_pos->y][(*game)->p_pos->x] = '0';
		(*game)->p_pos->x--;
		(*game)->moves++;
		ft_putnbr_fd((*game)->moves, 1);
	}
	else if ((*game)->map[(*game)->p_pos->y][(*game)->p_pos->x - 1] == 'E'
		&& (*game)->collected == true)
	{
		ft_putstr_fd("You won, thank you for playing!", 1);
		exit_game(game, NULL);
	}
}

void	move_right(t_mlx **game)
{
	if ((*game)->map[(*game)->p_pos->y][(*game)->p_pos->x + 1] != '1'
		&& (*game)->map[(*game)->p_pos->y][(*game)->p_pos->x + 1] != 'E')
	{
		(*game)->map[(*game)->p_pos->y][(*game)->p_pos->x + 1] = 'P';
		(*game)->map[(*game)->p_pos->y][(*game)->p_pos->x] = '0';
		(*game)->p_pos->x++;
		(*game)->moves++;
		ft_putnbr_fd((*game)->moves, 1);
	}
	else if ((*game)->map[(*game)->p_pos->y][(*game)->p_pos->x + 1] == 'E'
		&& (*game)->collected == true)
	{
		ft_putstr_fd("You won, thank you for playing!", 1);
		exit_game(game, NULL);
	}	
}
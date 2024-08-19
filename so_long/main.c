#include "so_long.h"

int	main(void)
{
	void	*mlx;
	void	*window;
	void	*image;
	int		width = 16;
	int		height = 16;

	mlx = mlx_init();
	if (!mlx)
		return (perror("mlx_init"), -1);
	window = mlx_new_window(mlx, 800, 600, "So_Long");
	if (!window)
		return (perror("mlx_new_window"), free(mlx), -1);
	image = mlx_xpm_file_to_image(mlx, "Orc-Peon-Cyan.xpm", &width, &height);
	if (!image)
		return (perror("mlx_xpm_file_to_image"), free(mlx), -1);
	mlx_put_image_to_window(mlx, window, image, 400, 300);
	sleep(10);
}
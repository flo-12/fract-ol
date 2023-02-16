
// https://aurelienbrabant.fr/blog/managing-events-with-the-minilibx

//$(CC) -Wall -Wextra -Werror -I/minilibx-linux -Imlx_linux -O3 -c $< -o $@
//cc mlx_test2.c -L./minilibx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
#include "./minilibx_linux/mlx.h"
#include "./minilibx_linux/mlx_int.h"
#include <stdio.h>
#include <unistd.h>

typedef struct	s_data {
	void	*mlx;
	void	*win;
}				t_data;

int	handle_no_event(t_data *data)
{
	// ...
	return (0);
}

int	handle_keypress(int key, t_data *data)
{
	if (key == XK_Escape)
		mlx_destroy_window(data->mlx, data->win);
	printf("Keypress: %d\n", key);
	return (0);
}

int	handle_keyrelease(int key, t_data *data)
{
	printf("Keyrelease: %d\n", key);
	return (0);
}

int	main()
{
	t_data	data;
	int		win_width = 700;
	int		win_height = 300;

	data.mlx = mlx_init();
	if (!data.mlx)
		return (1);
	data.win = mlx_new_window(data.mlx, win_width, win_height, "Our Window!");
	if (!data.win)
	{
		free(data.mlx);
		return (1);
	}

	mlx_loop_hook(data.mlx, &handle_no_event, &data);
	mlx_hook(data.win, KeyPress, KeyPressMask, &handle_keypress, &data);
	mlx_hook(data.win, KeyRelease, KeyReleaseMask, &handle_keyrelease, &data);

	mlx_loop(data.mlx);
	
	mlx_destroy_display(data.mlx);
	free(data.mlx);
	printf("THE END :(\n");
	return (0);
}

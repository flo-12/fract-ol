
//https://harm-smits.github.io/42docs/libs/minilibx/introduction.html

//$(CC) -Wall -Wextra -Werror -I/minilibx-linux -Imlx_linux -O3 -c $< -o $@
//cc mlx_xpm.c -L./minilibx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
#include "./minilibx_linux/mlx.h"
#include "./minilibx_linux/mlx_int.h"
#include <stdio.h>
#include <unistd.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void		*mlx;
	void		*win;
}				t_vars;

int	main()
{
	t_vars	vars;
	t_data	img;
	int		pic_width;
	int		pic_height;

	vars.mlx = mlx_init();
	if (!vars.mlx)
		return (1);
	vars.win = mlx_new_window(vars.mlx, 1000, 600, "XPM pic");
	if (!vars.win)
	{
		free(vars.mlx);
		return (1);
	}
	img.img = mlx_xpm_file_to_image(vars.mlx, "./img/img_test.xpm", &pic_width, &pic_height);
	if (!img.img)
		perror("ERROR");
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	/*mlx_destroy_image(vars.mlx, img.img);
	mlx_destroy_window(vars.mlx, vars.win);
	mlx_destroy_display(vars.mlx);
	free(vars.mlx);*/
	mlx_loop(vars.mlx);
	return (0);
}
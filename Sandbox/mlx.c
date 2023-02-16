
//https://harm-smits.github.io/42docs/libs/minilibx/introduction.html

//$(CC) -Wall -Wextra -Werror -I/minilibx-linux -Imlx_linux -O3 -c $< -o $@
//cc mlx.c -L./minilibx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
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

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;
	int		offset;

	offset = y * data->line_length + x * (data->bits_per_pixel / 8);
	dst = data->addr + offset;
	*(unsigned int*)dst = color;
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	hook_print(int x, int y, void *p)
{
	printf("Mouse movement at x=%d, y=%d\n", x, y);
	return (1);
}

int	hook_key(int key, t_vars *vars)
{
	// ESC -> 65307
	// <RightArrow> -> 65363
	if (key == 65307)
		exit (1);
	else if (key == 65363)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		vars->win = mlx_new_window(vars->mlx, 400, 100, "Right Arrow");
		mlx_hook(vars->win, KeyPress, KeyPressMask, hook_key, vars);
		mlx_hook(vars->win, MotionNotify, PointerMotionMask, hook_print, 0);
		//mlx_int_anti_resize_win(t_xvar *xvar,Window win,int w,int h);
	}
	else
		printf("key: %d\n", key);
	return (1);
}

int	hook_mouse(int key, int x, int y, t_vars *vars)
{
	printf("Mouse key %d at x=%d, y=%d pressed\n", key, x, y);
	return (1);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	t_data	img;
	int		width = 800;
	int		height = 500;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, width, height, "Hello World");
	img.img = mlx_new_image(vars.mlx, width, height);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	int	y = 0;
	int	x = 5;
	int	t;
	int	r, g, b;
	double	schade = 0.05;
	r = 0; g = 0; b = 255;
	while (y < height)
	{
		t = -1;
		while (++t <= 19)
			my_mlx_pixel_put(&img, x + t, y, create_trgb(255 / 6 * t, r, g, b * ((t + 1) * schade)));
		x++;
		y++;
	}
	while (x < width)
	{
		t = -1;
		while (++t <= 19)
			my_mlx_pixel_put(&img, x + t, y, create_trgb(255 / 6 * t, r, g, b * ((t + 1) * schade)));
		x++;
		y--;
	}
	while (y > 0)
	{
		t = -1;
		while (++t <= 19)
			my_mlx_pixel_put(&img, x + t, y, create_trgb(0, r, g, b * ((t + 1) * schade)));
		x--;
		y--;
	}
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_expose_hook(vars.win, hook_mouse, 0);
	mlx_key_hook(vars.win, hook_key, &vars);
	mlx_mouse_hook(vars.win, hook_mouse, 0);
	//mlx_loop_hook(vars.mlx, render_next_frame, &vars);
	//mlx_hook(vars.win, MotionNotify, PointerMotionMask, hook_print, 0);
	mlx_loop(vars.mlx);
	return (0);
}

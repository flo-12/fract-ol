
// https://aurelienbrabant.fr/blog/pixel-drawing-with-the-minilibx

//$(CC) -Wall -Wextra -Werror -I/minilibx-linux -Imlx_linux -O3 -c $< -o $@
//cc mlx_test3.c -L./minilibx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
#include "./minilibx_linux/mlx.h"
//#include "./minilibx_linux/mlx_int.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 300

#define RED_PIXEL 0x00FF0000
#define GREEN_PIXEL 0x0000FF00
#define BLUE_PIXEL 0x000000FF
#define BLACK_PIXEL 0x00000000
#define WHITE_PIXEL 0x00FFFFFF

#define KEY_ESC 65307

typedef struct s_img
{
	void	*image;
	char	*data;
	int		bpp;
	int		size_line;
//	int		endian;
	int		format;
}			t_img;

typedef struct	s_data {
	void	*mlx;
	void	*win;
	t_img	img;
}			t_data;

typedef struct s_rect
{
	int	x;
	int	y;
	int	width;
	int	height;
	int	color;
}			t_rect;


int	handle_keypress(int key, t_data *data)
{
	if (key = KEY_ESC)
	{
		mlx_destroy_window(data->mlx, data->win);
		data->win = NULL;
	}
	return (0);
}

int	encode_rgb(int red, int green, int blue)
{
	return (red << 16 | green << 8 | blue);
}

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->data + (img->size_line * y + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
	/*while (i >= 0)
	{
		if (img->format != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}*/
}

void	render_background(t_img *img, int color)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
			img_pix_put(img, j++, i, color);
		i++;
	}
}

int	render_rect(t_img *img, t_rect rect)
{
	int	i;
	int	j;

	i = rect.y;
	while (i < (rect.y + rect.height))
	{
		j = rect.x;
		while (j < (rect.x + rect.width))
			img_pix_put(img, j++, i, rect.color);
		i++;
	}
	return (0);
}

int	render(t_data *data)
{
	if (!data->win)
		return (1);
	render_background(&data->img, BLUE_PIXEL);
	render_rect(&data->img, (t_rect){WINDOW_WIDTH - 100, WINDOW_HEIGHT - 100,
			100, 100, GREEN_PIXEL});
	render_rect(&data->img, (t_rect){0, 0, 100, 100, RED_PIXEL});

	mlx_put_image_to_window(data->mlx, data->win, data->img.image, 0, 0);
	return (0);
}

int	main()
{
	t_data	data;
	t_rect	rect;

	data.mlx = mlx_init();
	if (!data.mlx)
		return (0);
	data.win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Pixel drawing with the miniblix!");
	if (!data.win)
	{
		free(data.mlx);
		return (0);
	}
	data.img.image = mlx_new_image(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!data.img.image)
	{
		// destroy_display, free(mlx), return
	}
	// what is the endian in t_img?
	data.img.data = mlx_get_data_addr(&data.img, &data.img.bpp, &data.img.size_line, &data.img.format);
	
	mlx_loop_hook(data.mlx, &render, &data);
	mlx_key_hook(data.win, &handle_keypress, &data);

	mlx_loop(data.mlx);

	mlx_destroy_display(data.mlx);
	free(data.mlx);
	return (0);
}


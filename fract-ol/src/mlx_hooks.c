/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:45:47 by fbecht            #+#    #+#             */
/*   Updated: 2023/02/21 11:45:49 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	handle_keypress(int key, t_data *data)
{
	if (key == KEY_ESC)
		exit_fractol(data, 0, EXIT_ESC);
	return (0);
}

int	handle_destroy(t_data *data)
{
	exit_fractol(data, 0, EXIT_CROSS);
	return (0);
}

int	hook_mouse(int key, int x, int y, t_data *data)
{
	ft_printf("key=%d (x=%d | y=%d)\n", key, x, y);
	if (key == MOUSE_WHEEL_UP)		// zoom in
	{
		data->fract.zoom += 0.1;
		data->fract.row_min = WINDOW_HEIGHT * (data->fract.zoom - 1) / 2;
		data->fract.row_max = WINDOW_HEIGHT * data->fract.zoom - data->fract.row_min;
		data->fract.col_min = WINDOW_WIDTH * (data->fract.zoom - 1) / 2;
		data->fract.col_max = WINDOW_WIDTH * data->fract.zoom - data->fract.col_min;
		mandelbrot(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img.image, 0, 0);
	}
	if (key == MOUSE_WHEEL_DOWN)	// zoom out
	{
		if ((int)(data->fract.zoom * 10) > 10)
		{
			data->fract.zoom -= 0.1;
			data->fract.row_min = WINDOW_HEIGHT * (data->fract.zoom - 1) / 2;
			data->fract.row_max = WINDOW_HEIGHT * data->fract.zoom - data->fract.row_min;
			data->fract.col_min = WINDOW_WIDTH * (data->fract.zoom - 1) / 2;
			data->fract.col_max = WINDOW_WIDTH * data->fract.zoom - data->fract.col_min;
			mandelbrot(data);
			mlx_put_image_to_window(data->mlx, data->win, data->img.image, 0, 0);
		}
		else
			ft_printf("%s\n", MAX_ZOOM_OUT);
	}
	return (0);
}

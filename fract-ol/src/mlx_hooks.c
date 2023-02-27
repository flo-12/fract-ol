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
	if (key == KEY_R)
	{
		ft_printf("Resetting to default\n");
		data->fract.zoom = 1;
		data->fract.row_min = 0;
		data->fract.row_max = WINDOW_HEIGHT;
		data->fract.col_min = 0;
		data->fract.col_max = WINDOW_WIDTH;
		data->fract.centre[0] = WINDOW_WIDTH / 2;
		data->fract.centre[1] = WINDOW_HEIGHT / 2;
		//if (data->fract.fractol == 'M')
			mandelbrot(data);
		//else
		//	julia(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img.image, 0, 0);
	}
	if (key == KEY_ONE)
		// reset to Mandelbrot
	if (key == KEY_TWO)
		// reset to Julia
	return (0);
}

int	handle_destroy(t_data *data)
{
	exit_fractol(data, 0, EXIT_CROSS);
	return (0);
}

void	set_zoom_val(int key, int x, int y, t_fractol *fract)
{
	fract->centre[0] = fract->centre[0] + (x - WINDOW_WIDTH / 2) / fract->zoom;
	fract->centre[1] = fract->centre[1] + (y - WINDOW_HEIGHT / 2) / fract->zoom;
	if (key == MOUSE_WHEEL_UP)
		fract->zoom *= ZOOM_FACTOR;
	else if (key == MOUSE_WHEEL_DOWN)
		fract->zoom *= 1 / ZOOM_FACTOR;
	fract->col_min = fract->centre[0] - (WINDOW_WIDTH / 2) / fract->zoom;
	fract->col_max = fract->col_min + WINDOW_WIDTH / fract->zoom;
	fract->row_min = fract->centre[1] - (WINDOW_HEIGHT / 2) / fract->zoom;
	fract->row_max = fract->row_min + WINDOW_HEIGHT / fract->zoom;
}

int	hook_mouse(int key, int x, int y, t_data *data)
{
	if (key == MOUSE_WHEEL_UP || key == MOUSE_WHEEL_DOWN)
	{
		if (key == MOUSE_WHEEL_DOWN
			&& !((int)(data->fract.zoom * 10) > 10))
		{
			ft_printf("%s\n", MAX_ZOOM_OUT);
			return (0);
		}
		set_zoom_val(key, x, y, &data->fract);
		//if (data->fract.fractol == 'M')
			mandelbrot(data);
		//else
		//	julia(data);
		mlx_put_image_to_window(data->mlx, data->win, data->img.image, 0, 0);
	}
	return (0);
}

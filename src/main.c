/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:24:34 by fbecht            #+#    #+#             */
/*   Updated: 2023/02/20 18:24:38 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	init_data(t_data *data, int argc, char **argv)
{
	if (argc == 1 || argc > 6)
		exit_fractol(data, 0, ARG_WRONG);
	init_fractol(data, argc, argv);
	data->mlx = mlx_init();
	if (!data->mlx)
		exit_fractol(data, 1, INIT_MLX);
	data->win = mlx_new_window(data->mlx, WINDOW_WIDTH,
			WINDOW_HEIGHT, "Fractol");
	if (!data->win)
		exit_fractol(data, 1, INIT_WIN);
	data->img.image = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!data->img.image)
		exit_fractol(data, 1, INIT_IMG);
	data->img.addr = mlx_get_data_addr(data->img.image, &data->img.bpp,
			&data->img.size_line, &data->img.endian);
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_bzero(&data, sizeof(data));
	init_data(&data, argc, argv);
	put_fractol(&data);
	mlx_key_hook(data.win, &handle_keypress, &data);
	mlx_mouse_hook(data.win, &hook_mouse, &data);
	mlx_hook(data.win, DestroyNotify, ButtonPressMask, &handle_destroy, &data);
	mlx_loop(data.mlx);
}

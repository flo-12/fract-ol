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

void	initialize_data(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit_fractol(data, 1, INIT_MLX);
	data->win = mlx_new_window(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "Fractol");
	if (!data->win)
	{
		exit_fractol(data, 1, INIT_WIN);
	}
	data->img.image = mlx_new_image(data->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!data->img.image)
	{
		exit_fractol(data, 1, INIT_IMG);
	}
	data->img.addr = mlx_get_data_addr(data->img.image, &data->img.bpp, &data->img.size_line, &data->img.endian);
}

int	main(int argc, char **argv)
{
	t_data	data;

	ft_bzero(&data, sizeof(data));
	if (!(argc == 3))
		exit_fractol(&data, 0, ARG_WRONG);
	if (!(!ft_strncmp(argv[1], "Mandelbrot", ft_strlen("Mandelbrot")) || !ft_strncmp(argv[1], "M", ft_strlen("M"))))
		exit_fractol(&data, 0, ARG_WRONG);

	initialize_data(&data);

	mandelbrot(&data, ft_atoi(argv[2]));
	mlx_put_image_to_window(data.mlx, data.win, data.img.image, 0, 0);
	mlx_key_hook(data.win, &handle_keypress, &data);
	mlx_hook(data.win, DestroyNotify, ButtonPressMask, &handle_destroy, &data);
	mlx_loop(data.mlx);

	//exit_fractol(&data, 0, SUCCESS);
	ft_printf("argc=%d , argv[0]=%s\n", argc, argv[0]);
}
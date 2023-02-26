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

int	main(int argc, char **argv)
{
	t_data	data;

	ft_bzero(&data, sizeof(data));
	init_data(&data, argc, argv);
	if (data.fract.fractol == 'M')
		mandelbrot(&data);
	else
		julia(&data);
	mlx_put_image_to_window(data.mlx, data.win, data.img.image, 0, 0);
	mlx_key_hook(data.win, &handle_keypress, &data);
	mlx_mouse_hook(data.win, &hook_mouse, &data);
	mlx_hook(data.win, DestroyNotify, ButtonPressMask, &handle_destroy, &data);
	mlx_loop(data.mlx);
}

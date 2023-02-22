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
	if (key == 4)
		// zoom in
	if (key == 5)
		// zoom out
	return (0);
}

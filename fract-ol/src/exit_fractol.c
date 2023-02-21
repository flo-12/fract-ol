/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_fractol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:40:03 by fbecht            #+#    #+#             */
/*   Updated: 2023/02/21 11:40:05 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	exit_fractol(t_data *data, int failure, char *text)
{
	if (data->img.image)
		mlx_destroy_image(data->mlx, data->img.image);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	if (failure)
	{
		perror(text);
		exit(EXIT_FAILURE);
	}
	else
	{
		ft_printf("%s\n", text);
		exit(EXIT_SUCCESS);
	}
}

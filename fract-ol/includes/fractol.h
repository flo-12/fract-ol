/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 18:42:13 by fbecht            #+#    #+#             */
/*   Updated: 2023/02/14 18:42:15 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "./Libft/libft.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include "./minilibx_linux/mlx.h"
# include "keys.h"
# include "colors.h"

#define WINDOW_WIDTH 600
#define WINDOW_HEIGHT 600

typedef struct s_img
{
	void	*image;
	char	*data;
	int		bpp;
	int		size_line;
	int		endian;
}			t_img;

typedef struct	s_data {
	void	*mlx;
	void	*win;
	t_img	img;
}			t_data;

#endif

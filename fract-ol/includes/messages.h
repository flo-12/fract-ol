/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   messages.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbecht <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:31:28 by fbecht            #+#    #+#             */
/*   Updated: 2023/02/21 11:31:30 by fbecht           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MESSAGES_H
# define MESSAGES_H

# define SUCCESS "Succesfull exit"

# define NO_ARG "Parameter must be passed to the program (./fractol <fractol> <...>)\n\t<fractol> \"Mandelbrot\" (or \"M\") or \"Julia\" (or \"J\")"
# define ARG_WRONG "Wrong input arguments"

# define INIT_MLX "initialize_data - data.mlx=NULL"
# define INIT_WIN "initialize_data - data.win=NULL"
# define INIT_IMG "initialize_data - data.img.image=NULL"

# define EXIT_ESC "Succesfull exit - ESC pressed"
# define EXIT_CROSS "Succesfull exit - cross pressed"

# define MAX_ZOOM_OUT "Zooming further out not possible -> reached lowest zoom value"

#endif

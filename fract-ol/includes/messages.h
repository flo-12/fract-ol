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

# define ARG_WRONG "[Error Input] Parameters must be passed to the program as followed: ./fractol <fractol> <...>\n\n\t for Mandelbrot: \"./fractol <\"Mandelbrot\" or \"M\"> <[optional] int max Iteration>\"\n\t for Julia: \"./fractol <\"Julia\" or \"J\"> <[optional] double C_Re> <[optional] double C_Im> <[optional] int max Iteration>\"\n\n\t int max Iterations is set by default to 400 if no parameter is passed\n\t C_Re and C_Im are set by default to -0.79 and 0.15 if no parameter is passed"
# define WRONG_ITER_MAX "[Warning] Passed parameter for iter_max not an int - set to default value "
# define NO_ITER_MAX "[Warning] No parameter for iter_max passed - set to default value "
# define WRONG_JULIA_C "[Warning] At least one of the passed parameters for C is not a double - set to default value "
# define NO_JULIA_C "[Warning] Less than two parameters for C passed - set to default value "

# define INIT_MLX "initialize_data - data.mlx=NULL"
# define INIT_WIN "initialize_data - data.win=NULL"
# define INIT_IMG "initialize_data - data.img.image=NULL"

# define EXIT_ESC "Succesfull exit - ESC pressed"
# define EXIT_CROSS "Succesfull exit - cross pressed"

# define MAX_ZOOM_OUT "Zooming further out not possible -> reached lowest zoom value"

#endif

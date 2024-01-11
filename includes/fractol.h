/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:10:41 by juramos           #+#    #+#             */
/*   Updated: 2024/01/11 10:40:04 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <mlx.h>
# include <math.h>
# include "libft.h"

/*	Dimensions	*/
# define WIDTH 800
# define HEIGHT 800
# define MAX_ITERATIONS 100

/*  Fractal sets	*/
# define MANDELBROT 1

typedef struct s_img {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_img;

typedef struct s_render {
	void	*mlx;
	void	*win;
}			t_render;

typedef struct s_complex {
	double	real;
	double	imag;
}			t_complex;

double		abs_complex(t_complex c);
t_complex	add_complex(t_complex a, t_complex b);
t_complex	square_complex(t_complex c);

#endif
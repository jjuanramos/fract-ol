/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:10:41 by juramos           #+#    #+#             */
/*   Updated: 2024/01/12 11:06:53 by juramos          ###   ########.fr       */
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

/* 
	Main struct: fractol. Contains:
	- mlx: struct returned by MLX. Used to manage the library.
	- img: struct returned by MLX. Used to store images (sets of pixels).
	- win: struct returned by MLX. Used to manage the window created by MLX.
	- set: type of fractal.
	- min_r: minimum real value given for the set.
	- max_r: maximum real value given for the set.
	- min_i: minimum imaginary value given for the set.
	- max_i: maximum imaginary value given for the set.
	- addr: memory address where the pixel data of the image is stored.
		The image uses a 32-bit per pixel format, where each pixel is
		represented by four consecutive bytes (4 bytes = 32 bits).
*/
typedef struct s_fractol {
	void	*mlx;
	void	*img;
	void	*win;
	int		set;
	int		min_r;
	int		max_r;
	int		min_i;
	int		max_i;
	char	*addr;
}	t_fractol;

void	init_f(t_fractol *f);
int		clean_close(t_fractol *f);
int		clean_exit(t_fractol *f, int exit_code);
int		msg(char *str, int errno);
#endif
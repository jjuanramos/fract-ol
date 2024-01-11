/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:10:41 by juramos           #+#    #+#             */
/*   Updated: 2024/01/11 14:00:44 by juramos          ###   ########.fr       */
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
	- img: struct returned by MLX. Used to store images (sets of pixels).
	- mlx: struct returned by MLX. Used to manage the library.
	- win: struct returned by MLX. Used to manage the window created by MLX.
	- set: type of fractal.
	- min_r: minimum real value given for the set.
	- max_r: maximum real value given for the set.
	- min_i: minimum imaginary value given for the set.
	- max_i: maximum imaginary value given for the set.
	- addr: address that represents the beginning of the memory area where the image is stored.
*/
typedef struct s_fractol {
	void	*img;
	void	*mlx;
	void	*win;
	int		set;
	int		min_r;
	int		max_r;
	int		min_i;
	int		max_i;
	char	*addr;
}	t_fractol;

void	init_f(t_fractol *f);

#endif
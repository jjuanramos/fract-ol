/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:10:41 by juramos           #+#    #+#             */
/*   Updated: 2024/01/12 17:26:54 by juramos          ###   ########.fr       */
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

/*	Buttons	*/
# define CLOSE_BUTTON 17

/* t_fractol:
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
	- default_color: the color that we paint the set with if an alternative isn't
		provided.
	- palette: color palette that goes from a variable color to black (0x000000).
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
	int		default_color;
	int		*palette;
}	t_fractol;


/*	Initializations	*/
void	init_f(t_fractol *f);

/*	Utils	*/
int		clean_close(t_fractol *f);
int		clean_exit(t_fractol *f, int exit_code);
int		msg(char *str, int errno);

/*	Render	*/
void	render(t_fractol *f);

/*	Color	*/
void	set_palette(t_fractol *f, int alt_color);

/*	Sets */
int		mandelbrot(double pr, double pi);

#endif
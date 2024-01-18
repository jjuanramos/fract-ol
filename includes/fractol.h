/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:10:41 by juramos           #+#    #+#             */
/*   Updated: 2024/01/18 11:56:13 by juramos          ###   ########.fr       */
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
# define JULIA 2
# define TRICORN 3

/*	Buttons & Keys	*/
# define CLOSE_BUTTON 17
# define KEY_ESC 65307
# define KEY_W 119
# define KEY_A 97
# define KEY_S 115
# define KEY_D 100
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_LEFT 65361
# define KEY_RIGHT 65363
# define KEY_PLUS 61
# define KEY_MINUS 45
# define KEY_SPACE 32
# define KEY_ONE 49
# define KEY_TWO 50
# define KEY_THREE 51
# define KEY_FOUR 52
# define KEY_FIVE 53
# define MOUSE_WHEEL_UP 4
# define MOUSE_WHEEL_DOWN 5
# define MOUSE_WHEEL_BTN 3
# define MOUSE_BTN 1
# define MOUSE_BTN_2 3
# define KEY_K 107

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
	- color: the color that we paint the set with if an alternative isn't
		provided.
	- palette: color palette that goes from a variable color to black (0x000000).
	- kr: constant real value used for the Julia set.
	- ki: constant imaginary value used for the Julia set.
*/
typedef struct s_fractol {
	void	*mlx;
	void	*img;
	void	*win;
	int		set;
	double	min_r;
	double	max_r;
	double	min_i;
	double	max_i;
	char	*addr;
	int		color;
	int		*palette;
	double	kr;
	double	ki;
}	t_fractol;


/*	Initializations	*/
void	init_f(t_fractol *f);
void	reinit_f(t_fractol *f);

/*	Utils	*/
int		clean_close(t_fractol *f);
int		clean_exit(t_fractol *f, int exit_code);
int		msg(char *str, int errno);
void	print_controls(void);
int		print_and_exit(int errno);

/*	Render	*/
void	render(t_fractol *f);

/*	Color	*/
void	set_palette(t_fractol *f, int *colors, int n);

/*	Sets */
int		mandelbrot(double pr, double pi);
int		julia(t_fractol *f, double pr, double pi);
int		tricorn(double pr, double pi);

/*	Events	*/
int		key_event(int keycode, t_fractol *f);
int		mouse_event(int keycode, int x, int y, t_fractol *f);

/*	Args	*/
void	handle_args(t_fractol *f, int argc, char **argv);

#endif
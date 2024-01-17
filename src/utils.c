/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:37:13 by juramos           #+#    #+#             */
/*   Updated: 2024/01/17 12:46:31 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* clean_close:
	performs a clean_exit and returns a 0.
	used for event hooks.
*/
int	clean_close(t_fractol *f)
{
	clean_exit(f, 0);
	return (0);
}

/* clean_exit:
	frees everything related to MiniLibX
	before exiting.
*/
int	clean_exit(t_fractol *f, int exit_code)
{
	if (!f)
		exit(exit_code);
	if (f->palette)
		free(f->palette);
	if (f->img)
		mlx_destroy_image(f->mlx, f->img);
	if (f->win && f->mlx)
		mlx_destroy_window(f->mlx, f->win);
	if (f->mlx)
	{
		mlx_loop_end(f->mlx);
		mlx_destroy_display(f->mlx);
		free(f->mlx);
	}
	exit(exit_code);
}

/* msg:
	used to send messages to stderr.
	returns errno so it can be used in tandem with clean_exit.
*/
int	msg(char *str, int errno)
{
	ft_putstr_fd(str, 2);
	return (errno);
}


void	print_controls(void)
{
	ft_putendl_fd("===============  Fract`ol  ===============", 1);
	ft_putendl_fd("Fractals available:", 1);
	ft_putendl_fd("\tM - Mandelbrot", 1);
	ft_putendl_fd("\tJ - Julia", 1);
	ft_putendl_fd("\tT - Tricorn", 1);
	ft_putendl_fd("\tYou can customize the color after setting the Fractal", 1);
	ft_putendl_fd("\t\tExample: ./fractol M 0xFFFFFF", 1);
	ft_putendl_fd("\t\tExample: ./fractol T 0xFFFFFF", 1);
	ft_putendl_fd("\tYou can customize the params of the Julia set", 1);
	ft_putendl_fd("\t\tExample: ./fractol J -0.7 -0.3", 1);
	ft_putendl_fd("\tYou can also custom the Julia set color, such as", 1);
	ft_putendl_fd("\t\tExample: ./fractol J -0.7 -0.3 0xFF0000", 1);
	ft_putendl_fd("Controls:", 1);
	ft_putendl_fd("\tUse the arrows to move around the window", 1);
	ft_putendl_fd("\tUse the W and D or the mouse to zoom in and out", 1);
	ft_putendl_fd("\tUse the spacebar to go back to the default zoom", 1);
}

int	print_and_exit(int errno)
{
	print_controls();
	exit(errno);
}

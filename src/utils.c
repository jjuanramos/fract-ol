/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:37:13 by juramos           #+#    #+#             */
/*   Updated: 2024/01/15 12:45:01 by juramos          ###   ########.fr       */
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
	ft_putendl_fd("fractals available:", 1);
	ft_putendl_fd("\tM - Mandelbrot", 1);
	ft_putendl_fd("\tJ - Julia", 1);
}

char	parse_set(char **str)
{
	if (str[1][0] != 'M' && str[1][0] != 'J')
	{
		print_controls();
		return ('\0');
	}
	else
		return (str[1][0]);
}

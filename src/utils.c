/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 10:37:13 by juramos           #+#    #+#             */
/*   Updated: 2024/01/12 11:08:17 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	clean_close(t_fractol *f)
{
	clean_exit(f, 0);
	return (0);
}

int	clean_exit(t_fractol *f, int exit_code)
{
	if (!f)
		exit(exit_code);
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

int	msg(char *str, int errno)
{
	ft_putstr_fd(str, 2);
	return (errno);
}

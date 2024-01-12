/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:53:51 by juramos           #+#    #+#             */
/*   Updated: 2024/01/12 10:32:20 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	init_img(t_fractol *f)
{
	int	bits_per_pixel;
	int	line_length;
	int	endian;

	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img)
	{
		ft_putstr_fd(
			"Initialization of win failed. Exiting programme.\n",
			2);
		exit(1);
	}
	f->addr = mlx_get_data_addr(f->img, &bits_per_pixel, &line_length, &endian);
}

void	init_f(t_fractol *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
	{
		ft_putstr_fd(
			"Initialization of mlx failed. Exiting programme.\n",
			2);
		exit(1);
	}
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "fractol");
	if (!f->win)
	{
		ft_putstr_fd(
			"Initialization of win failed. Exiting programme.\n",
			2);
		exit(1);
	}
	init_img(f);
	f->min_r = -4;
	f->max_r = 4;
	f->min_i = -4;
	f->max_i = 4;
}

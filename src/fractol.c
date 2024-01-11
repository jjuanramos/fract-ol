/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:10:40 by juramos           #+#    #+#             */
/*   Updated: 2024/01/11 14:04:07 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
	Current purpose: Open a window with a basic set of pixels.
*/

static void	set_pixel_color(t_fractol *f, int x, int y, int color)
{
	f->addr[x * 4 + y * WIDTH * 4] = color;
	f->addr[x * 4 + y * WIDTH * 4 + 1] = color >> 8;
	f->addr[x * 4 + y * WIDTH * 4 + 2] = color >> 16;
	f->addr[x * 4 + y * WIDTH * 4 + 3] = color >> 24;
}

static void	render(t_fractol *f)
{
	int			x;
	int			y;
	int			color_iter;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			// pr = f->min_r + (double)x * (f->max_r - f->min_r) / WIDTH;
			// pi = f->max_i + (double)y * (f->min_i - f-> max_i) / HEIGHT;
			color_iter = (MAX_ITERATIONS * x) / WIDTH;
			set_pixel_color(f, x, y, color_iter);
		}
	}
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	mlx_loop(f->mlx);
}

int	main(void)
{
	t_fractol	f;
	// double		pr;
	// double		pi;

	init_f(&f);
	render(&f);
}

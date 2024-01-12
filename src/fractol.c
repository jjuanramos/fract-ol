/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:10:40 by juramos           #+#    #+#             */
/*   Updated: 2024/01/12 10:32:34 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* set_pixel_color:
	Add a color to one pixel of the MLX image map.
	The MLX image is composed of 32 bits per pixel.
	Color ints are stored from right to left, here, and are in
	the form of 0xAARRGGBB. 8 bits encode each color component,
	Alpha (Transparency), Red, Green and Blue.
	Bit shifting:
		- BB >> 0   (0x000000BB)
		- GG >> 8   (0x0000GG00)
		- RR >> 16  (0x00RR0000)
		- AA >> 24  (0xAA000000)
	The image uses a 32-bit per pixel format,
	where each pixel's color is represented by a 32-bit integer
	in the form of 0xAARRGGBB.
	We extract each component of the color from the bit value (color)
	and assign it to each byte of (x, y).
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
	exit(0);
}

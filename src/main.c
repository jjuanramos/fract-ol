/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:10:40 by juramos           #+#    #+#             */
/*   Updated: 2024/01/11 10:51:35 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	custom_close(int keycode, t_render *render)
{
	mlx_destroy_window(render->mlx, render->win);
	return (keycode);
}

int	close_exit(t_render *render)
{
	mlx_destroy_window(render->mlx, render->win);
	exit(0);
}

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	mandelbrot(t_complex c)
{
	t_complex	z;
	int			n;

	n = 0;
	z = c;
	while (abs_complex(z) <= 2 && n < MAX_ITERATIONS)
	{
		z = add_complex(square_complex(z), c);
		n++;
	}
	return (n);
}

// real = x * (x_max - x_min) / (width - 1) + x_min
// imag = y * (y_max - y_min) / (height - 1) + y_min
// we apply the formula above with x_max, y_max = 2 and x_min, y_min = -2,
// this formula will give to our real and imag values the proportionally equal
// values in that scale.
void	paint_img(t_img *img, int width, int length)
{
	int				x;
	int				y;
	t_complex		c;
	int				n;

	y = -1;
	while (y++ < length - 1)
	{
		x = -1;
		// printf(" ");
		while (x++ < width - 1)
		{
			c.real = x * 4 / (width - 1) - 2;
			c.imag = y * 4 / (length - 1) - 2;
			n = mandelbrot(c);
			// printf("%d ", n);
			if (n == 100)
				my_mlx_pixel_put(img, x, y, 0xFF000000);
			else if (n == 2)
				my_mlx_pixel_put(img, x, y, 0x00FF0000);
			else if (n == 1)
				my_mlx_pixel_put(img, x, y, 0x0000FF00);
			else if (n == 0)
				my_mlx_pixel_put(img, x, y, 0xFFFFFFFF);
		}
		// printf("\n");
	}
}

int	main(void)
{
	t_img		img;
	t_render	render;

	render.mlx = mlx_init();
	render.win = mlx_new_window(render.mlx, WIDTH, HEIGHT, "Hello world!");
	img.img = mlx_new_image(render.mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(
			img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	paint_img(&img, WIDTH, HEIGHT);
	mlx_put_image_to_window(render.mlx, render.win, img.img, 0, 0);
	mlx_hook(render.win, 2, 1L << 0, custom_close, &render);
	mlx_hook(render.win, 17, 1L << 1, close_exit, &render);
	mlx_loop(render.mlx);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:10:40 by juramos           #+#    #+#             */
/*   Updated: 2024/01/10 12:55:18 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <mlx.h>
#include <math.h>

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}			t_vars;

typedef struct Complex {
	double	real;
	double	imag;
}			t_complex;

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

double	abs_complex(t_complex c)
{
	return (sqrt(pow(c.real, 2) + pow(c.imag, 2)));
}

t_complex	add_complex(t_complex a, t_complex b)
{
	t_complex	c;

	c.real = a.real + b.real;
	c.imag = a.imag + b.imag;
	return (c);
}

t_complex	square_complex(t_complex c)
{
	t_complex	n;

	n.real = pow(c.real, 2) - pow(c.imag, 2);
	n.imag = 2 * c.real * c.imag;
	return (n);
}

int	close(int keycode, t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return (0);
}

int	close_exit(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	mandelbrot(t_complex c)
{
	t_complex	z;
	int			n;

	n = 0;
	z = c;
	while (abs_complex(z) < 2 && n < 100)
	{
		z = add_complex(square_complex(z), c);
		n++;
	}
	return (n);
}

unsigned int interpolate_color(unsigned int color1, unsigned int color2, int n, int maxN) {
    // Extract the red, green, and blue components of color1
    int r1 = (color1 >> 16) & 0xFF;
    int g1 = (color1 >> 8) & 0xFF;
    int b1 = color1 & 0xFF;

    // Extract the red, green, and blue components of color2
    int r2 = (color2 >> 16) & 0xFF;
    int g2 = (color2 >> 8) & 0xFF;
    int b2 = color2 & 0xFF;

    // Calculate interpolated red component
    int r = r1 + (r2 - r1) * n / maxN;

    // Calculate interpolated green component
    int g = g1 + (g2 - g1) * n / maxN;

    // Calculate interpolated blue component
    int b = b1 + (b2 - b1) * n / maxN;

    // Combine the interpolated components to form the resulting color
    return (r << 16) | (g << 8) | b;
}

// real = x * (x_max - x_min) / (width - 1) + x_min
// imag = y * (y_max - y_min) / (height - 1) + y_min
// we apply the formula above with x_max, y_max = 2 and x_min, y_min = -2,
// this formula will give to our real and imag values the proportionally equal
// values in that scale.
void	paint_whole_window(t_data *data, int width, int length)
{
	int				x;
	int				y;
	t_complex		c;
	int				n;
	unsigned int	color;

	y = -1;
	while (y++ < length - 1)
	{
		x = -1;
		while (x++ < width - 1)
		{
			c.real = x * 4 / (width - 1) - 2;
			c.imag = y * 4 / (length - 1) - 2;
			n = mandelbrot(c);
			color = interpolate_color(0xFFFFFFFF, 0xFF000000, n, 100);
			my_mlx_pixel_put(data, x, y, color);
		}
	}
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 800, "Hello world!");
	img.img = mlx_new_image(vars.mlx, 800, 800);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
		&img.endian);
	paint_whole_window(&img, 800, 800);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 0, 0);
	mlx_hook(vars.win, 2, 1L << 0, close, &vars);
	mlx_hook(vars.win, 17, 1L << 1, close_exit, &vars);
	mlx_loop(vars.mlx);
}

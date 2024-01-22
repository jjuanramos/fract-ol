/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 11:53:51 by juramos           #+#    #+#             */
/*   Updated: 2024/01/22 16:56:32 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	clean_init(t_fractol *f)
{
	f->mlx = NULL;
	f->win = NULL;
	f->img = NULL;
	f->addr = NULL;
	f->set = -1;
	f->min_r = 0;
	f->max_r = 0;
	f->min_i = 0;
	f->max_i = 0;
	f->kr = 0;
	f->ki = 0;
	f->palette = NULL;
	f->colors = NULL;
	f->color = 0;
}

/* init_img:
	takes a t_fractol struct with initialized window and initializes
	an img on it.
*/
static void	init_img(t_fractol *f)
{
	int	bits_per_pixel;
	int	line_length;
	int	endian;

	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!f->img)
		clean_exit(f, msg("Initialization of win failed.\n", 1));
	f->addr = mlx_get_data_addr(f->img, &bits_per_pixel, &line_length, &endian);
}

/* init_f:
	initializes a t_fractol with the basic settings.
*/
void	init_f(t_fractol *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		clean_exit(f, msg("Initialization of mlx failed.\n", 1));
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "fractol");
	if (!f->win)
		clean_exit(f, msg("Initialization of win failed.\n", 1));
	init_img(f);
	set_palette(f, f->colors, 6);
}

void	set_dimensions(t_fractol *f)
{
	f->min_r = -2;
	f->max_r = 2;
	f->max_i = -2;
	f->min_i = f->max_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
}

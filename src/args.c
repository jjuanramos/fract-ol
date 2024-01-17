/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:56:51 by juramos           #+#    #+#             */
/*   Updated: 2024/01/17 11:39:15 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	parse_set(t_fractol *f, char **str)
{
	char	set;

	if (str[1][0] != 'M' && str[1][0] != 'J')
		print_and_exit(1);
	else
		set = str[1][0];
	if (set == 'M')
		f->set = MANDELBROT;
	else if (set == 'J')
		f->set = JULIA;
}

static void	get_color(t_fractol *f, int argc, char **argv)
{
	f->color = 0xFFFF00;
	if (argc == 3)
		f->color = ft_atox_color(argv[2]);
	else if (f->set == JULIA && argc == 5)
		f->color = ft_atox_color(argv[4]);
	if (!(argc == 2 || (f->set == JULIA && argc == 4))
		&& (f->color == -1))
		print_and_exit(1);
}

static void	get_params(t_fractol *f, int argc, char **argv)
{
	f->min_r = -2;
	f->max_r = 2;
	f->max_i = -2;
	f->min_i = f->max_i + (f->max_r - f->min_r) * HEIGHT / WIDTH;
	if (f->set == JULIA)
	{
		if (argc == 4 || argc == 5)
		{
			f->kr = ft_atod(argv[2]);
			f->ki = ft_atod(argv[3]);
			if (f->kr > 2.0 || f->kr < -2.0 || f->ki >= 2.0 || f->ki <= -2.0)
				print_and_exit(1);
		}
		else
		{
			f->kr = -0.75;
			f->ki = -0.080000;
		}
	}
}

void	handle_args(t_fractol *f, int argc, char **argv)
{
	parse_set(f, argv);
	if ((f->set == MANDELBROT && argc > 3) || (f->set == JULIA && argc > 5))
		print_and_exit(1);
	get_color(f, argc, argv);
	get_params(f, argc, argv);
}


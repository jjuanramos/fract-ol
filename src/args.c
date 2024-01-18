/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 09:56:51 by juramos           #+#    #+#             */
/*   Updated: 2024/01/18 13:09:04 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	parse_set(t_fractol *f, char **str)
{
	char	set;

	if (str[1][0] != 'M' && str[1][0] != 'J' && str[1][0] != 'T')
		print_and_exit(1);
	else
		set = str[1][0];
	if (set == 'M')
		f->set = MANDELBROT;
	else if (set == 'J')
		f->set = JULIA;
	else if (set == 'T')
		f->set = TRICORN;
}

static void	get_color(t_fractol *f, int argc, char **argv)
{
	int	is_color;

	is_color = 0;
	if (argc == 3)
	{
		f->color = ft_atox_color(argv[2]);
		is_color++;
	}
	else if (f->set == JULIA && argc == 5)
	{
		f->color = ft_atox_color(argv[4]);
		is_color++;
	}
	else if (!(argc == 2 || (f->set == JULIA && argc == 4)))
		print_and_exit(1);
	set_color_range(f, is_color);
}

static void	get_params(t_fractol *f, int argc, char **argv)
{
	set_dimensions(f);
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
	if ((f->set == MANDELBROT && argc > 3) || (f->set == JULIA && argc > 5)
		|| (f->set == TRICORN && argc > 3))
		print_and_exit(1);
	get_color(f, argc, argv);
	get_params(f, argc, argv);
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:54:09 by juramos           #+#    #+#             */
/*   Updated: 2024/01/12 14:05:58 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	mandelbrot(double pr, double pi)
{
	double	z;
	double	cr;
	double	ci;
	double	temp_i;
	int		n;

	cr = pr;
	ci = pi;
	n = -1;
	while (++n < MAX_ITERATIONS)
	{
		z = pr * pr + pi * pi;
		if (z > 4)
			break ;
		temp_i = 2 * pr * pi + ci;
		pr = (pr * pr - pi * pi) + cr;
		pi = temp_i;
	}
	return (n);
}

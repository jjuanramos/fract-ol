/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 13:54:09 by juramos           #+#    #+#             */
/*   Updated: 2024/01/17 12:43:36 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* mandelbrot:
	calculates the mandelbrot set for each complex number
	z formed by the real part pr and the imaginary, pi.
	Returns how stable the given z is, the closer it is to
	MAX_ITERATIONS, the more stable it is.
*/
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

int	tricorn(double pr, double pi)
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
		temp_i = -2 * pr * pi + ci;
		pr = (pr * pr - pi * pi) + cr;
		pi = temp_i;
	}
	return (n);
}

int	julia(t_fractol *f, double pr, double pi)
{
	double	z;
	double	temp_i;
	int		n;

	n = -1;
	while (++n < MAX_ITERATIONS)
	{
		z = pr * pr + pi * pi;
		if (z > 4)
			break ;
		temp_i = 2 * pr * pi + f->ki;
		pr = (pr * pr - pi * pi) + f->kr;
		pi = temp_i;
	}
	return (n);
}

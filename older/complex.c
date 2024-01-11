/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 13:12:37 by juramos           #+#    #+#             */
/*   Updated: 2024/01/10 13:19:58 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
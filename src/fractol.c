/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:10:40 by juramos           #+#    #+#             */
/*   Updated: 2024/01/12 17:23:30 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(void)
{
	t_fractol	f;

	init_f(&f);
	render(&f);
	mlx_hook(f.win, CLOSE_BUTTON, 0, clean_close, &f);
	mlx_loop(f.mlx);
	exit(0);
}

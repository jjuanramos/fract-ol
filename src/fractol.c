/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/10 10:10:40 by juramos           #+#    #+#             */
/*   Updated: 2024/01/23 16:05:37 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	leaks(void)
{
	system("leaks fractol");
}

int	main(int argc, char **argv)
{
	t_fractol	f;

	atexit(leaks);
	if (argc < 2)
	{
		print_controls();
		return (1);
	}
	clean_init(&f);
	handle_args(&f, argc, argv);
	init_f(&f);
	render(&f);
	mlx_hook(f.win, CLOSE_BUTTON, 0, clean_close, &f);
	mlx_key_hook(f.win, key_event, &f);
	mlx_mouse_hook(f.win, mouse_event, &f);
	mlx_loop(f.mlx);
	exit(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 09:30:48 by juramos           #+#    #+#             */
/*   Updated: 2024/01/18 13:02:52 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	zoom(t_fractol *f, double z)
{
	double	center_r;
	double	center_i;

	center_r = f->min_r - f->max_r;
	center_i = f->max_i - f->min_i;
	f->max_r = f->max_r + (center_r - z * center_r) / 2;
	f->min_r = f->max_r + z * center_r;
	f->min_i = f->min_i + (center_i - z * center_i) / 2;
	f->max_i = f->min_i + z * center_i;
}

static void	move(t_fractol *f, char dir, double dist)
{
	double	center_r;
	double	center_i;

	center_r = f->max_r - f->min_r;
	center_i = f->max_i - f->min_i;
	if (dir == 'R')
	{
		f->min_r += center_r * dist;
		f->max_r += center_r * dist;
	}
	else if (dir == 'L')
	{
		f->min_r -= center_r * dist;
		f->max_r -= center_r * dist;
	}
	else if (dir == 'D')
	{
		f->min_i -= center_i * dist;
		f->max_i -= center_i * dist;
	}
	else if (dir == 'U')
	{
		f->min_i += center_i * dist;
		f->max_i += center_i * dist;
	}
}

int	mouse_event(int keycode, int x, int y, t_fractol *f)
{
	if (keycode == MOUSE_WHEEL_UP)
	{
		zoom(f, 0.5);
		x -= WIDTH / 2;
		y -= HEIGHT / 2;
		if (x < 0)
			move(f, 'L', (double)x * -1 / WIDTH);
		else if (x > 0)
			move(f, 'R', (double)x / WIDTH);
		if (y < 0)
			move(f, 'U', (double)y * -1 / HEIGHT);
		else if (y > 0)
			move (f, 'D', (double)y / HEIGHT);
	}
	else if (keycode == MOUSE_WHEEL_DOWN)
		zoom(f, 2);
	else
		return (0);
	render(f);
	return (0);
}

int	key_event(int keycode, t_fractol *f)
{
	if (keycode == KEY_ESC)
		return (clean_close(f));
	else if (keycode == KEY_W)
		zoom(f, 0.5);
	else if (keycode == KEY_D)
		zoom(f, 2);
	else if (keycode == KEY_UP)
		move(f, 'U', 0.2);
	else if (keycode == KEY_DOWN)
		move(f, 'D', 0.2);
	else if (keycode == KEY_LEFT)
		move(f, 'L', 0.2);
	else if (keycode == KEY_RIGHT)
		move(f, 'R', 0.2);
	else if (keycode == KEY_SPACE)
		set_dimensions(f);
	else
		return (1);
	render(f);
	return (0);
}

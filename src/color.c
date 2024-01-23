/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:40:31 by juramos           #+#    #+#             */
/*   Updated: 2024/01/23 11:18:28 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* interpolate:
	the interpolate function takes 2 colors, color1 and color2, and
	a double value, fraction, and:
	1. Separates, through bit shifting, each color into an array
		where each position is occupied by its gradient of red, green,
		and blue respectively.
	2. Calculates what the equivalent color, given the fraction, would
		result if we were to get it from a straight line where color1
		is the beginning and color2 is the end.
	3. Puts up the new gradient of colors into one, and returns that.
*/
int	interpolate(int color1, int color2, double fraction)
{
	int	start_rgb[4];
	int	end_rgb[4];

	start_rgb[0] = (color1 >> 24) & 0xFF;
	start_rgb[1] = (color1 >> 16) & 0xFF;
	start_rgb[2] = (color1 >> 8) & 0xFF;
	start_rgb[3] = color1 & 0xFF;
	end_rgb[0] = (color2 >> 24) & 0xFF;
	end_rgb[1] = (color2 >> 16) & 0xFF;
	end_rgb[2] = (color2 >> 8) & 0xFF;
	end_rgb[3] = color2 & 0xFF;
	start_rgb[0] = (end_rgb[0] - start_rgb[0]) * fraction + start_rgb[0];
	start_rgb[1] = (end_rgb[1] - start_rgb[1]) * fraction + start_rgb[1];
	start_rgb[2] = (end_rgb[2] - start_rgb[2]) * fraction + start_rgb[2];
	start_rgb[3] = (end_rgb[3] - start_rgb[3]) * fraction + start_rgb[3];
	return (start_rgb[0] << 24 | start_rgb[1] << 16
		| start_rgb[2] << 8 | start_rgb[3]);
}

/* set_palette:
	this function takes a pointer to f and an alternative
	color, and creates a gradient of color from baseline to
	alt color until half of the iterations have been completed,
	and then goes from the alt color to white until the
	MAX_ITERATIONS - 1 iteration, last iteration is set to black.
	so, the number of possible colors is equivalent to the number of
	iterations that the set performs to decide whether the value is stable.
*/
void	set_palette(t_fractol *f, int *colors, int n)
{
	int		color_pos;
	int		i;
	int		j;
	double	fraction;

	i = 0;
	color_pos = 0;
	f->palette = ft_calloc(MAX_ITERATIONS + 1, sizeof(int));
	if (!f->palette)
		clean_exit(f, msg("Initialization of palette failed.\n", 1));
	while (i < MAX_ITERATIONS)
	{
		j = 0;
		while ((i + j) < MAX_ITERATIONS && j < MAX_ITERATIONS / (n - 1))
		{
			fraction = (double)j / (MAX_ITERATIONS / (n - 1));
			f->palette[i + j] = interpolate(
					colors[color_pos], colors[color_pos + 1], fraction);
			j++;
		}
		color_pos++;
		i += j;
	}
	f->palette[MAX_ITERATIONS - 1] = 0;
}

void	set_color_range(t_fractol *f, int is_color)
{
	int		*colors;
	int		i;

	colors = (int [6]){0x4C5B5C,
		0xFF715B, 0xF9CB40, 0xBCED09, 0x2F52E0, 0xFFFFFF};
	i = -1;
	f->colors = ft_calloc(7, sizeof(int));
	if (!is_color)
	{
		while (++i < 6)
			f->colors[i] = colors[i];
	}
	else
	{
		while (++i < 6)
			f->colors[i] = interpolate(colors[i], f->color, 1.75 / 6);
	}
}

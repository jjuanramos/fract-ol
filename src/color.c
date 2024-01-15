/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:40:31 by juramos           #+#    #+#             */
/*   Updated: 2024/01/13 12:33:46 by juramos          ###   ########.fr       */
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
static int	interpolate(int color1, int color2, double fraction)
{
	int	start_rgb[3];
	int	end_rgb[3];

	start_rgb[0] = ((color1 >> 16) & 0xFF);
	start_rgb[1] = ((color1 >> 8) & 0xFF);
	start_rgb[2] = ((color1 >> 0) & 0xFF);
	end_rgb[0] = ((color2 >> 16) & 0xFF);
	end_rgb[1] = ((color2 >> 8) & 0xFF);
	end_rgb[2] = ((color2 >> 0) & 0xFF);
	start_rgb[0] = (end_rgb[0] - start_rgb[0]) * fraction + start_rgb[0];
	start_rgb[1] = (end_rgb[1] - start_rgb[1]) * fraction + start_rgb[1];
	start_rgb[2] = (end_rgb[2] - start_rgb[2]) * fraction + start_rgb[2];
	return (0xFF << 24 | start_rgb[0] << 16 | start_rgb[1] << 8 | start_rgb[2]);
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
void	set_palette(t_fractol *f, int alt_color)
{
	int		baseline_color;
	int		i;
	int		j;
	double	fraction;

	i = 0;
	baseline_color = 0x000000;
	f->palette = ft_calloc(MAX_ITERATIONS, sizeof(int));
	if (!f->palette)
		clean_exit(f, msg("Initialization of palette failed.\n", 1));
	while (i < MAX_ITERATIONS)
	{
		j = 0;
		while (j < MAX_ITERATIONS / 2)
		{
			fraction = (double)j / (MAX_ITERATIONS / 2);
			f->palette[i + j] = interpolate(
					baseline_color, alt_color, fraction);
			j++;
		}
		baseline_color = alt_color;
		alt_color = 0xFFFFFF;
		i += j;
	}
	f->palette[MAX_ITERATIONS -1] = 0;
}
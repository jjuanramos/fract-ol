/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/12 12:40:31 by juramos           #+#    #+#             */
/*   Updated: 2024/01/12 16:36:33 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* interpolate
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
	color, and creates a gradient of color from that alternative
	color to the baseline color that is equivalent to the number
	of iterations that the set performs to decide whether the value
	is stable. That means that the closer to the baseline, the more
	stable the value is.
*/
void	set_palette(t_fractol *f, int alt_color)
{
	int		baseline_color;
	int		i;
	int		j;
	double	fraction;

	i = 0;
	baseline_color = 0x000000;
	f->palette = ft_calloc(MAX_ITERATIONS + 1, sizeof(int));
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

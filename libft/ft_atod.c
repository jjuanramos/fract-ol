/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:28:24 by juramos           #+#    #+#             */
/*   Updated: 2024/01/17 11:03:04 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == ' ' || c == '\n'
		|| c == '\f' || c == '\r'
		|| c == '\t' || c == '\v')
		return (1);
	return (0);
}

static char	*remove_whitespaces(char *str)
{
	int	pos;

	pos = 0;
	while (ft_isspace(str[pos]))
		pos++;
	return (&str[pos]);
}

static	void	move_to_right(char **str, int *pos, double *sign)
{
	if (*str[0] == '+')
		(*pos)++;
	else if (*str[0] == '-')
	{
		*sign *= -1.0;
		(*pos)++;
	}
}

static double	pow_zero(int size)
{
	double	result;

	result = 0.1;
	while (size != 0 && --size)
		result *= 0.1;
	return (result);
}

/* ft_atod:
	specifically tailored for fract'ol, that's why it returns
	42: because it is used to parse julia params, that can't be
	greater than 2, so when it fails we return a value greater than
	that one in order to let the program know that it's failed.
*/
double	ft_atod(char *str)
{
	double	sign;
	double	num;
	int		pos;

	str = remove_whitespaces(str);
	pos = 0;
	num = 0.0;
	sign = 1.0;
	move_to_right(&str, &pos, &sign);
	while (str[pos] != '\0')
	{
		if (ft_isdigit(str[pos]))
			num = num * 10.0 + (str[pos] - 48);
		else if (str[pos] == '.')
		{
			pos++;
			num += (ft_atod(&str[pos]) * pow_zero((ft_strlen(str) - pos)));
			return (num * sign);
		}
		else
			return (42);
		pos++;
	}
	return (num * sign);
}

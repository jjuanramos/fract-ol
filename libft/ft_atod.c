/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atod.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/16 16:28:24 by juramos           #+#    #+#             */
/*   Updated: 2024/01/16 10:49:47 by juramos          ###   ########.fr       */
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

static const char	*remove_whitespaces(const char *str)
{
	int	pos;

	pos = 0;
	while (ft_isspace(str[pos]))
		pos++;
	return (&str[pos]);
}

double	ft_atod(const char *str)
{
	double	sign;
	double	num;
	int		pos;

	str = remove_whitespaces(str);
	pos = 0;
	num = 0.0;
	sign = 1.0;
	if (str[0] == '+')
		pos++;
	else if (str[0] == '-')
	{
		sign *= -1.0;
		pos++;
	}
	while (str[pos] != '\0')
	{
		if (ft_isdigit(str[pos]))
			num = num * 10.0 + (str[pos] - 48);
		else
			return (num * sign);
		pos++;
	}
	return (num * sign);
}

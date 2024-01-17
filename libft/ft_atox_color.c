/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atox_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:14:31 by juramos           #+#    #+#             */
/*   Updated: 2024/01/17 11:25:42 by juramos          ###   ########.fr       */
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

static char	*remove_whitespaces_0x(char *str)
{
	int	pos;

	pos = 0;
	while (ft_isspace(str[pos])
		|| (str[pos] == '0'))
	{
		if ((str[pos] == '0'))
		{
			if (str[pos + 1] && str[pos + 1 == 'x'])
				pos += 2;
			else
				return (NULL);
		}
		else
			pos++;
	}
	return (&str[pos]);
}

int	ft_atox_color(char	*str)
{
	int	i;
	int	len;
	int	num;

	i = 0;
	len = 0;
	num = 0;
	str = remove_whitespaces_0x(str);
	while (str[i] && ft_ishex(str[i]))
	{
		if (ft_isdigit(str[i]))
			num = num * 16 + str[i] - '0';
		else
			num = num * 16 + ft_toupper(str[i]) - 'A' + 10;
		i++;
		len++;
	}
	if (len == 6 && !str[i])
		return (num);
	else
		return (-1);
}

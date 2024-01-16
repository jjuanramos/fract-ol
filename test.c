/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juramos <juramos@student.42madrid.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:14:18 by juramos           #+#    #+#             */
/*   Updated: 2024/01/16 17:44:07 by juramos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int	is_hex(char s)
{
	if (!(s >= '0' && s <= '9')
		&& !(ft_toupper(s) >= 'A' && ft_toupper(s) <= 'F'))
		return (0);
	return (1);
}

int	atoc(char	*str)
{

	return (0);
}

int	main(void)
{
	char	*s;
	int		s_c;

	s = "0xFFFFFF";
	printf("%s converted is %d, which equals %d.\n", s, atoc(s_c), 0xFFFFFF);
	ft_putnbr_base_fd(2827171, "123456789ABCDEF", 1);
	printf("\n");
	return (0);
}

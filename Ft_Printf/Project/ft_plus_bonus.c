/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_plus_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzanana <mzanana@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 18:50:41 by mzanana           #+#    #+#             */
/*   Updated: 2025/02/05 12:45:46 by mzanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_checksign(int *x, char c, int *y)
{
	if (*x == 0)
	{
		if (c == '+')
			ft_putchar('0', y);
		if (c == ' ')
			ft_putstr(" 0", y);
		return (0);
	}
	else if (*x > 0)
	{
		if (c == '+')
			ft_putchar('+', y);
		else if (c == ' ')
			ft_putchar(' ', y);
		return (*x);
	}
	else
	{
		ft_putchar('-', y);
		(*x) = -(*x);
		return (*x);
	}
}

void	ft_plus(int x, char c, int *y)
{
	char	str[12];
	char	*hold;
	int		i;

	if (x == -2147483648)
	{
		ft_putstr("-2147483648", y);
		return ;
	}
	hold = "0123456789";
	x = ft_checksign(&x, c, y);
	i = 0;
	while (x > 0)
	{
		str[i++] = hold[x % 10];
		x /= 10;
	}
	while (--i >= 0)
		ft_putchar(str[i], y);
}

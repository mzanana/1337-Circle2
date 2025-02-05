/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzanana <mzanana@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:51:52 by mzanana           #+#    #+#             */
/*   Updated: 2025/02/05 12:47:00 by mzanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_isnegatif(int *x, int *y)
{
	if (*x == 0)
		ft_putchar('0', y);
	else if (*x < 0)
	{
		ft_putchar('-', y);
		(*x) = -(*x);
	}
	return ;
}

void	ft_putnbr(int x, int *y)
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
	ft_checksign(&x, y);
	i = 0;
	while (x > 0)
	{
		str[i++] = hold[x % 10];
		x /= 10;
	}
	while (--i >= 0)
		ft_putchar(str[i], y);
}

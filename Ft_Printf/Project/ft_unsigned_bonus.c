/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzanana <mzanana@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:00:59 by mzanana           #+#    #+#             */
/*   Updated: 2025/02/05 13:03:59 by mzanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_unsigned(unsigned int x, int *y)
{
	char	str[12];
	char	*hold;
	int		i;

	if (x == 0)
		return (ft_putchar('0', y));
	hold = "0123456789";
	i = 0;
	while (x > 0)
	{
		str[i++] = hold[x % 10];
		x /= 10;
	}
	while (--i >= 0)
		ft_putchar(str[i], y);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzanana <mzanana@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:35:31 by mzanana           #+#    #+#             */
/*   Updated: 2025/02/04 16:29:24 by mzanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

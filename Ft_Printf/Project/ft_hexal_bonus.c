/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexal_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzanana <mzanana@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 20:44:38 by mzanana           #+#    #+#             */
/*   Updated: 2025/02/05 12:51:07 by mzanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_hexal(unsigned int nb, int *x, char *str, char c)
{
	char	buf[12];
	int		i;

	if (nb == 0)
	{
		ft_putchar('0', x);
		return ;
	}
	i = 0;
	while (nb > 0)
	{
		buf[i++] = str[nb % 16];
		nb /= 16;
	}
	if (c == 'x')
		ft_putstr("0x", x);
	else if (c == 'X')
		ft_putstr("0X", x);
	while (--i >= 0)
		ft_putchar(buf[i], x);
}

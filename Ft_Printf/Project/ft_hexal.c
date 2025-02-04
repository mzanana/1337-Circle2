/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzanana <mzanana@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:42:26 by mzanana           #+#    #+#             */
/*   Updated: 2025/02/04 16:17:55 by mzanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_hexal(unsigned int nb, int *x, char *str)
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
	while (--i >= 0)
		ft_putchar(buf[i], x);
}

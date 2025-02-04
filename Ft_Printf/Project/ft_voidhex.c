/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_voidhex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzanana <mzanana@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:29:52 by mzanana           #+#    #+#             */
/*   Updated: 2025/02/04 16:31:07 by mzanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_voidhex(unsigned long nbr, int *x)
{
	char	*hold;
	char	str[20];
	int		i;

	if (!nbr)
	{
		ft_putstr("(nil)", x);
		return ;
	}
	hold = "0123456789abcdef";
	i = 0;
	while (nbr > 0)
	{
		str[i] = hold[nbr % 16];
		nbr /= 16;
		i++;
	}
	ft_putstr("0x", x);
	while (--i >= 0)
		ft_putchar(str[i], x);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzanana <mzanana@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:42:26 by mzanana           #+#    #+#             */
/*   Updated: 2025/02/04 15:42:36 by mzanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_hexal(unsigned int nb, int *x, char c)
{
    char	*lower;
	char	*upper;

    lower = "0123456789abcdef";
    upper = "0123456789ABCDEF";
    if (nb == 0)
    {
        ft_putchar('0', x);
        return;
    }
    else if (nb >= 16)
	{
        ft_hexal(nb/16, x, c);
	}
	if (c == 'x')
		ft_putchar(lower[nb%16], x);
	else if (c == 'X')
		ft_putchar(upper[nb%16], x);
}
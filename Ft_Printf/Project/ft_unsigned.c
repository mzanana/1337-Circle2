/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unsigned.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzanana <mzanana@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:35:31 by mzanana           #+#    #+#             */
/*   Updated: 2025/02/04 15:35:39 by mzanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_calcule2(unsigned int nb)
{
	int	ret;

	ret = 0;
	while (nb > 0)
	{
		nb /= 10;
		ret++;
	}
	return (ret);
}

void	ft_unsigned(unsigned int nb, int *x)
{
	int lenght;
	char *str;

	if (nb == 0)
        return (ft_putchar('0', x));
    lenght = ft_calcule2(nb);
	str = malloc(sizeof(char) * (unsigned int)(lenght + 1));
	if(!str)
		return;
	str[lenght] = '\0';
	while (--lenght >= 0)
	{
		str[lenght] = nb % 10 + 48;
		nb /= 10;
	}
	ft_putstr(str, x);
	free(str);
}
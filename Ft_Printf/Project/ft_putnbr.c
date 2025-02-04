/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzanana <mzanana@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:51:52 by mzanana           #+#    #+#             */
/*   Updated: 2025/02/04 15:25:00 by mzanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_calcule(int nb)
{
	int	ret;

	ret = 0;
	if (nb <= 0 )
	{
		nb = -nb;
		ret = 1;
	}
	while (nb > 0)
	{
		nb /= 10;
		ret++;
	}
	return (ret);
}

int ft_isnegatif(int *i, int *j)
{
	if((*i) < 0)
	{
		(*i) = -(*i);
		(*j) = 1;
		return (1);
	}
	return (0);
}

void	ft_putnbr(int nb, int *x)
{
	int		lenght;
	int		stop;
	char	*str;

	if (nb == -2147483648)
	{
		ft_putstr("-2147483648", x);
		return;
	}
	lenght = ft_calcule(nb);
	str = malloc(sizeof(char) * (lenght + 1));
	if (!str)
		return;
	str[lenght] = '\0';
	stop = 0;
	if (ft_isnegatif(&nb, &stop))
		str[0] = '-';
	while (--lenght >= stop)
	{
		str[lenght] = nb % 10 + 48;
		nb /= 10;
	}
	ft_putstr(str, x);
	free(str);
}

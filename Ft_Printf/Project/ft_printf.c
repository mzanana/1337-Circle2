/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzanana <mzanana@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:51:22 by mzanana           #+#    #+#             */
/*   Updated: 2025/02/04 16:13:51 by mzanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strchr(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_helper(va_list args, char c, int *i)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), i);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), i);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), i);
	else if (c == 'u')
		ft_unsigned(va_arg(args, unsigned int), i);
	else if (c == 'p')
		ft_voidhex(va_arg(args, unsigned long), i);
	else if (c == 'x')
		ft_hexal(va_arg(args, unsigned int), i, 'x');
	else if (c == 'X')
		ft_hexal(va_arg(args, unsigned int), i, 'X');
	else if (c == '%')
		ft_putchar('%', i);
	return (*i);
}

int	ft_printf(const char *str, ...)
{
	int		ret;
	int		i;
	va_list	args;

	if (!str)
		return (-1);
	va_start(args, str);
	i = 0;
	ret = 0;
	while (str[i])
	{
		if (str[i] == '%' && ft_strchr("cspdiuxX%", str[i + 1]))
		{
			i++;
			ret = ft_helper(args, str[i], &ret);
		}
		else
			ft_putchar(str[i], &ret);
		i++;
	}
	return (ret);
}

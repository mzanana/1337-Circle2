/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzanana <mzanana@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:51:22 by mzanana           #+#    #+#             */
/*   Updated: 2025/02/05 12:53:46 by mzanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

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

int	ft_bonuscheck(va_list args, char flag, char next, int *ret)
{
	if (flag == '+' && (next == 'd' || next == 'i'))
		ft_plus(va_arg(args, int), '+', ret);
	else if (flag == ' ' && (next == 'd' || next == 'i'))
		ft_plus(va_arg(args, int), ' ', ret);
	else if (flag == '#' && next == 'x')
		ft_hexal(va_arg(args, unsigned int), ret, "0123456789abcdef", 'x');
	else if (flag == '#' && next == 'X')
	{
		ft_hexal(va_arg(args, unsigned int), ret, "0123456789abcdef", 'X');
	}
	return (*ret);
}

int	ft_helper(va_list args, char c, int *i)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), i);
	else if (c == 's')
		ft_putstr(va_arg(args, char *), i);
	else if (c == 'p')
		ft_voidhex(va_arg(args, unsigned long), i);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(args, int), i);
	else if (c == 'u')
		ft_unsigned(va_arg(args, unsigned int), i);
	else if (c == 'x')
		ft_hexal(va_arg(args, unsigned int), i, "0123456789abcdef", 'x');
	else if (c == 'X')
		ft_hexal(va_arg(args, unsigned int), i, "0123456789abcdef", 'X');
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
		if (str[i] == '%' && ft_strchr("cspdiuxX%# +", str[i + 1]))
		{
			i++;
			if (ft_strchr("# +", str[i]) && str[i + 1])
			{
				ret = ft_bonuscheck(args, str[i], str[i + 1], &ret);
				i++;
			}
			else if (ft_strchr("cspdiuxX%", str[i]))
				ret = ft_helper(args, str[i], &ret);
		}
		else
			ft_putchar(str[i], &ret);
		i++;
	}
	return (ret);
}

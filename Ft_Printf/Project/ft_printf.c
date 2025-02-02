#include "ft_printf.h"

int	ft_helper(va_list args, char c, int *i)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int), i);
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
		if (str[i] == '%' && str[i + 1])
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

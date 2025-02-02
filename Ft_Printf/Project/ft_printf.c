#include "ft_printf.h"



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
		
			ft_putchar(str[i], &ret);
		i++;
	}
	return (ret);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzanana <mzanana@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:52:03 by mzanana           #+#    #+#             */
/*   Updated: 2025/02/05 13:03:55 by mzanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	ft_putstr(char *str, int *x)
{
	int	i;

	if (!str)
	{
		write (1, "(nill)", 6);
		(*x) += 6;
		return ;
	}
	i = 0;
	while (str[i])
	{
		write (1, &str[i], 1);
		i++;
		(*x)++;
	}
}

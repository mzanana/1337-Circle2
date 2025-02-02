/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzanana <mzanana@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:51:32 by mzanana           #+#    #+#             */
/*   Updated: 2025/02/02 15:51:34 by mzanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include <stdarg.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

int ft_printf(const char *str, ...);
void ft_putchar(char c, int *x);
void ft_putnbr(int nb, int *x);
void	ft_putstr(char *str, int *x);
void    ft_voidhex(void *str, int *x);

# endif

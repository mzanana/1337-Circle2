/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzanana <mzanana@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 15:51:32 by mzanana           #+#    #+#             */
/*   Updated: 2025/02/04 21:50:11 by mzanana          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_putchar(char c, int *x);
void	ft_putnbr(int nb, int *x);
void	ft_putstr(char *str, int *x);
void	ft_voidhex(unsigned long nbr, int *x);
void	ft_unsigned(unsigned int nb, int *x);
void	ft_hexal(unsigned int nb, int *x, char *str, char c);
int		ft_strchr(char *str, char c);
//void	ft_hashtag(void f(unsigned int x, int *y, char z), char a);
void	ft_plus(int x, char c, int *y);
#endif

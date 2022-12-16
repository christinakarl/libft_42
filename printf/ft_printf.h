/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 15:08:25 by ckarl             #+#    #+#             */
/*   Updated: 2022/12/16 14:22:13 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>


int		ft_printf(const char *, ...);
void	ft_put_c(int *put, int b);
void	ft_put_di(int *put, int n);
void	ft_put_u(int *put, unsigned int);
void	ft_put_s(int *put, char *s);
void	ft_put_x(int *put, unsigned int n, const char minmaj);
void	ft_put_ptr(int *put, unsigned long p);
void	hex_ptr(int *put, unsigned long n);
void	print_decide(int *put, char const c, va_list args);
int		is_conv(char const c);

#endif

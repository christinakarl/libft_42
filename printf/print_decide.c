/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_decide.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:38:30 by ckarl             #+#    #+#             */
/*   Updated: 2022/12/16 14:21:57 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_conv(char const c)
{
	if (c == 'c' || c == 'd' || c == 'p' || c == 'i' ||
		 c == 's' || c == 'x' || c == 'X' || c == 'u' || c == '%')
		return (1);
	else
		return (0);
}

void	print_decide(int *put, char const c, va_list args)
{
	if (c == 'c')
		ft_put_c(put, va_arg(args, int));
	else if (c == 'd' || c == 'i')
		ft_put_di(put, va_arg(args, int));
	else if (c == 'p')
		ft_put_ptr(put, va_arg(args, unsigned long));
	else if (c == 's')
		ft_put_s(put, va_arg(args, char *));
	else if (c == 'x' || c == 'X')
		ft_put_x(put, va_arg(args, unsigned int), c);
	else if (c == 'u')
		ft_put_u(put, va_arg(args, unsigned int));
	else if (c == '%')
		put += write(1, "%", 1);
}

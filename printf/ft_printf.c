/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:38:30 by ckarl             #+#    #+#             */
/*   Updated: 2022/10/27 17:12:36 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>

imp	*ft_init(imp *put)
{
	put.len = 0;
	return (put);
}
//set the structure imp's component to 0 (except of the args)

int	ft_printf(const char *print, ...)
{
	imp		*put;
	int		len;
	int		i;

	i = 0;
	len = 0;
	va_start(args, print);

	while (print[++i])
	{
		if (print[i] == '%')


	}

	//len always + write(...) because write returns an int

	va_end(args);
	return (len);
}
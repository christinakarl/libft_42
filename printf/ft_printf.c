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

#include "ft_printf.h"
#include <stdio.h>

int	ft_printf(const char *print, ...)
{
	int			*put;
	va_list		args;
	int			len;
	int			i;

	i = 0;
	len = 0;
	/*put = (int *)malloc(sizeof(int));
	if (!put)
		return (-1); //or -1, TBD*/
	put = &len;

	va_start(args, print);
	while (print[++i])
	{
		if (print[i] == '%')
		{
			print_decide(put, print[i + 1], args);
		}
		else
			len += write(1, &print[i], 1);
	}

	va_end(args);
	printf("%d\n", len);
	return (len);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_ptr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:38:30 by ckarl             #+#    #+#             */
/*   Updated: 2022/12/16 14:20:54 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	hex_ptr(int *put, unsigned long n)
{
	if (n >= 16)
	{
		hex_ptr(put, (n / 16));
		hex_ptr(put, (n % 16));
	}
	else
	{
		if (n <= 9)
			ft_put_c(put, (n + 48));
		else
			ft_put_c(put, (n - 10 + 97));
	}
}

void	ft_put_ptr(int *put, unsigned long p)
{
	put += write(1, "0x", 2);
	if (p == 0)
		put += write(1, "0", 1);
	hex_ptr(put, p);
}

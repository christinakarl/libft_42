/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_x.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 16:38:30 by ckarl             #+#    #+#             */
/*   Updated: 2022/12/16 14:19:04 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_put_x(int *put, unsigned int n, const char minmaj)
{
	if (n >= 16)
	{
		ft_put_di(put, (n / 16));
		ft_put_di(put, (n % 16));
	}
	else
	{
		if (n <= 9)
			ft_put_c(put, (n + 48));
		else
		{
			if (minmaj == 'x')//10 - 15 = a, b, c, d, e, f
				ft_put_c(put, (n - 10 + 97));
			else
				ft_put_c(put, (n - 10 + 65));
		}
	}
}

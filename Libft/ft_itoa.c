/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/04 09:54:56 by ckarl             #+#    #+#             */
/*   Updated: 2022/11/17 14:33:05 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_islen(int n)
{
	int	len;

	len = 0;
	if (n < 0)
	{
		n *= -1;
		len++;
	}
	while (n != 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	i = ft_islen(n);
	str = (char *)malloc(sizeof(char) * (i + 1));
	str[i--] = '\0';
	if (n == 0)
		str[0] = '0';
	else if (n < 0)
	{
		if (n == -2147483648)
		{
			str[1] = '2';
			n += 2000000000;
		}
		str[0] = '-';
		n *= -1;
	}
	while (n > 0)
	{
		str[i--] = n % 10 + 48;
		n = n / 10;
	}
	return (str);
}

int	main(void)
{
	int	n;
	char	*str;

	n = 19076;
	str = ft_itoa(n);
	printf("%s\n", str);
	return (0);
}

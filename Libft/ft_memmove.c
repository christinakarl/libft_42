/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 11:58:33 by ckarl             #+#    #+#             */
/*   Updated: 2022/10/28 13:57:40 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	*ft_memmove(void *str1, const void *str2, size_t n)
{
	unsigned int	i;
	char		*s2;
	char		*s1;

	s1 = (char *)str1;
	s2 = (char *)str2;
	i = 0;
	if (s2 < s1)
	{
		while (n > 0)
		{
			s1[n] = s2[n];
			n--;
		}
	}
	else
	{	
		while (i < n)
		{
			s1[i] = s2[i];
			i++;
		}
	}
	return (str1);
}

int	main(void)
{
	char	*str1;
	size_t		n;

	str1 = "Baum";
	n = 2;
	printf("%s\n", ft_memmove(str1, &str1[1], n));
	printf("%s\n", memmove(str1, &str1[1], n));
	return (0);
}

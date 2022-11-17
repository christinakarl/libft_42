/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 16:50:08 by ckarl             #+#    #+#             */
/*   Updated: 2022/10/27 17:07:58 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	size_t	i;
	char	b;

	b = (char)c;
	str = (char*)s;
	i = ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == b)
			return (&str[i]);
		i--;
	}
	return (NULL);
}

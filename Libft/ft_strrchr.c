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

size_t	ft_strlen(const char *str);

char	*ft_strrchr(const char *s, int c)
{
	char	*str;
	size_t		i;
	
	str = (char*)s;
	i = ft_strlen(str) - 1;
	if (c == '\0')
		return (NULL);
	while (i >= 0)
	{
		if (str[i] == c)
			return (&str[i]);
		i--;
	}
	return (NULL);
}

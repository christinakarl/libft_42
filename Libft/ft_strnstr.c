/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/09 13:51:35 by ckarl             #+#    #+#             */
/*   Updated: 2022/10/27 17:27:43 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	size_t	i;
	size_t	j;
	char	*str1;
	char	*to_find1;

	to_find1 = (char*)to_find;
	str1 = (char*)str;
	i = 0;
	j = 0;
	if (to_find1[i] == '\0')
		return (str1);
	while (str1[i] != '\0' && i < len)
	{
		if (str1[i] == to_find1[j])
		{
			if (to_find1[j + 1] == '\0')
				return (&str1[i - j]);
			i++;
			j++;
		}
		else
		{
			i++;
			j = 0;
		}
	}
	return (NULL);
}

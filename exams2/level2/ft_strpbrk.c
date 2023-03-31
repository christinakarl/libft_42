/* ****************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 15:50:23 by ckarl             #+#    #+#             */
/*   Updated: 2023/03/31 16:12:39 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ****************************************************************************/

//The function strpbrk() is used to find the first character of first string and matches it to any character of second string.
//It returns NULL, if no matches are found otherwise, it returns a pointer to the character of first string that matches to the character of second string.
//Here is the syntax of strpbrk() in C language:
//char *strpbrk(const char *string1, const char *string2)

#include <stdio.h>
#include <unistd.h>

char	*ft_strpbrk(const char *s1, const char *s2)
{
	int	i;
	int j;
	char	*str1 = (char *)s1;
	char	*str2 = (char *)s2;

	i = 0;
	j = 0;
	while (str1[i])
	{
		while (str2[j])
		{
			if (str1[i] == str2[j])
				return (&str1[i]);
			j++;
		}
		j = 0;
		i++;
	}
	return(NULL);
}


int	main(void)
{
	const char	*str1 = "HAllo12";
	const char	*str2 = "Mhacht";

	if (ft_strpbrk(str1, str2) == NULL)
		write(1, "(null)", 6);
	else
		write(1, ft_strpbrk(str1, str2), 1);
	return (0);
}

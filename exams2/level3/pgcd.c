/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pgcd.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 18:40:01 by ckarl             #+#    #+#             */
/*   Updated: 2023/03/31 19:09:42 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//pcgc = biggest common denominator of two int variables

#include <stdio.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);	
}

//need to check for negative numbers
int	ck_atoi(char *str)
{
	int	new;
	int	i;
	int	len;

	len = ft_strlen(str);
	i = 0;
	new = 0;
	if (len == 1 && str[i] == '0')
	   return (0);
	while (str[i])
	{
		new *= 10;
		new += str[i] - '0';
		i++;
	}	
	return (new);
}

//transform argv's into int's
//find biggest common denominator

int	main(void)
{
	int	atoi;

	atoi = ck_atoi("-234");
	printf("%d\n", atoi);

	return (0);
}

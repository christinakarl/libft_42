/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake_to_camel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 13:57:33 by ckarl             #+#    #+#             */
/*   Updated: 2023/03/31 14:47:51 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//Write a program that takes a single string in lowerCamelCase format
//and converts it into a string in snake_case format. 
//A snake_case string is a string where each word is in lower case, separated by
//an underscore "_".
//A lowerCamelCase string is a string where each word begins with a capital letter
//except for the first one.

#include <stdio.h>
#include <unistd.h>

void	ck_putchar (char c)
{
	write(1, &c, 1);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;

	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}

	 while (argv[1][i] != '\0')
	 {
	 	if (argv[1][i] >= 'A' && argv[1][i] <= 'Z')
		{
			ck_putchar('_');
			ck_putchar(argv[1][i] + 32);
		}
		else
			ck_putchar(argv[1][i]);
		i++;
	 }
	return (0);
}

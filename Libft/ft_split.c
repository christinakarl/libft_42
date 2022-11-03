/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 13:19:20 by ckarl             #+#    #+#             */
/*   Updated: 2022/11/02 18:35:50 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int words(char *s, char c)
{
    int i;
    int count;

    i = 0;
    count = 1;
    while (s[i] != '\0')
    {
        if (s[i] == c)
            count += 1;

    }

}  

char    **ft_split(char const *s, char c)
{
    char    *str;
    char    **tab;
    int     i;
    int     indicator;



}
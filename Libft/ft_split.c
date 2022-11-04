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

int ft_words(char *s, char c)
{
    int i;
    int count;
    int index;

    i = 0;
    count = 0;
    index = 1;
    while (s[i] != '\0')
    {
        if (s[i] == c && index == 0)
            index = 1;
        else if (index == 1 && s[i] != c)
        {
            index = 0;
            count += 1;
        }
        i++;
    }
    return (count);
}  

char    *ft_dup(char *str, int start, int end)
{
    int     i;
    char    *copy;

    i = 0;
    copy = (char *)malloc(sizeof(*copy) * (end - start + 1));
    if (!copy)
        return (NULL);
    


}

char    **ft_split(char const *s, char c)
{
    char    *str;
    char    **tab;
    int     i;
    int     index;
    int     words;

    words = ft_words(str,c)
    str = (char *)s;
    i = 0;
    tab = (char **)malloc(sizeof(char *) * (words + 1));
    if (!tab || !str)
        return (NULL);
    


}
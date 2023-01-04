/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:47:55 by ckarl             #+#    #+#             */
/*   Updated: 2023/01/04 19:02:06 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//fd = file descriptor returned by open()

//check if temp contains '\n'
int	checkcont(void *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

//read-loop
void	ft_read(c_list *copy, int fd, char *temp)
{
	temp = (char *)malloc(BUFFER_SIZE, sizeof(char));
	read(fd, temp, BUFFER_SIZE);
	copy->content = temp;
	free(temp);
}

char	*get_next_line(int fd)
{
	char			*final;
	static c_list	*copy;	
	int				i;
	int				a;

	i = 0;
	temp = 0;
//read the file until '\n' is found (which would mean checkcont != -1
	while (checkcont(copy->content) == -1)
	{
		ft_read(copy, fd, temp);
		copy = copy->next;
	}
//copy linked list to final string
	while ()
	{
		x = 0;
		while ((copy->content)[x])
			final[i++] = (copy->content)[x++];
		copy = copy->next;
	}

	return (final);
}

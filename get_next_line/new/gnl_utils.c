/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:47:55 by ckarl             #+#    #+#             */
/*   Updated: 2023/01/04 19:02:06 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"


//get size of linked list
int	ft_lstsize(c_list *lst)
{
	int		i;
	int		len;

	len = 0;
	while (lst)
	{
		i = 0;
		while(lst->content[i])
		{
			if(lst->content[i] == '\n')
			{
				len++;
				break;
			}
			i++;
			len++;
		}
		lst = lst->next;
	}
	return (len);
}

//create the line
void	ft_getline(char **line, c_list *list)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	len = ft_lstsize(list);
	(*line) = (char *)malloc(sizeof(char)* (len + 1));
	if (!(*line))
		return;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			(*line)[j] = (list->content)[i];
			if (list->content[i] == '\n')
				break;
			i++;
			j++;
		}
		list = list->next;
	}
	(*line)[j] = '\0';
}


/*join two strings (list->content to final string)
char	*ft_strjoin(c_list *list)
{
	char			*copy;
	int				i;
	unsigned int	listlen;
	c_list			*temp;

	listlen = ft_lstsize(list) - 1;
	temp = ft_lstlast(list);
	i = 0;
	copy = (char *)malloc(sizeof(*copy) * ((listlen * BUFFER_SIZE) + checkcont(temp->content) + 1));
	if (!copy)
		return (NULL);
	while(list != 0)
	{
		while (list->content[i])
		{
			copy[i] = list->content[i];
			i++;
			if (list->content[i - 1] == '\n')
				break;
		}
		list = list->next;
	}
	copy[i] = '\0';
	return (copy);
}*/
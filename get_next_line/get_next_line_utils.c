/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:47:55 by ckarl             #+#    #+#             */
/*   Updated: 2023/02/24 14:56:28 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"


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
	while (list != NULL)
	{
		i = 0;
		while (list->content[i] && list->content[i] != '\n')
			(*line)[j++] = (list->content)[i++];
		if (list->content[i] == '\n')
			(*line)[j++] = list->content[i];
		list = list->next;
	}
	(*line)[j] = '\0';
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	clear_list(c_list **list)
{
	c_list	*next;
	
	while (*list != NULL)
	{
		next = (*list)->next;
		free((*list)->content);
		(*list) = next;
	}
	free(*list);
}

void	new_list(c_list **list)
{
	c_list	*future;
	c_list	*copy;
	int		i;
	int		j;

	i = 0;
	j = 0;
	future = (c_list *)malloc(sizeof(c_list));
	if (future == NULL || list == NULL)
		return;
	copy = ft_lstlast(*list);
	while (copy->content[i])
	{
		if (copy->content[i++] == '\n')
			break;
		i++;
	}
	future->content = (char *)malloc(sizeof(char) * ((ft_strlen(copy->content) - i) + 1));
	while (copy->content[i] != '\0')
		future->content[j++] = copy->content[i++];
	future->content[j] = '\0';
	future->next = NULL;
	clear_list(list);
	*list = future;
}


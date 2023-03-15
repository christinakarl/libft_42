/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:51:45 by ckarl             #+#    #+#             */
/*   Updated: 2023/03/02 11:51:47 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

//get size of linked list
int	ft_lstsize(t_list *lst)
{
	int		i;
	int		len;

	len = 0;
	while (lst)
	{
		i = 0;
		while (lst->content[i] && lst->content[i] != '\n')
		{
			i++;
			len++;
		}
		if (lst->content[i] == '\n')
			len++;
		lst = lst->next;
	}
	return (len);
}

//create the line
void	ft_getline(char **line, t_list *list)
{
	int	i;
	int	j;
	int	len;

	j = 0;
	len = ft_lstsize(list);
	(*line) = (char *)malloc(len + 1);
	if (!(*line))
		return ;
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

void	clear_list(t_list **list)
{
	t_list	*next;

	while (*list != NULL)
	{
		next = (*list)->next;
		free((*list)->content);
		free(*list);
		(*list) = next;
	}
}

void	new_list(t_list **list)
{
	t_list	*future;
	t_list	*copy;
	int		i;
	int		j;

	i = 0;
	j = 0;
	future = (t_list *)malloc(sizeof(t_list));
	if (future == NULL || list == NULL)
		return ;
	copy = ft_lastitem(*list);
	while (copy->content[i] && copy->content[i] != '\n')
		i++;
	if (copy->content[i] == '\n')
		i++;
	future->content = malloc((ft_strlen(copy->content) - i) + 1);
	while (copy->content[i] != '\0')
		future->content[j++] = copy->content[i++];
	future->content[j] = '\0';
	future->next = NULL;
	clear_list(list);
	*list = future;
}

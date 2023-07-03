/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ck_list_helpers2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:04:19 by ckarl             #+#    #+#             */
/*   Updated: 2023/06/30 12:59:57 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//append new node to list
void	list_append(t_env_list **lst, char *element)
{
	t_env_list	*addback;
	t_env_list	*copy;

	addback = (t_env_list *)malloc(sizeof(t_env_list));
	if (!addback)
		return ;
	addback->next = NULL;
	addback->element = ft_strdup(element);
	if (!addback->element)							//add error message
		return ;
	if (*lst == NULL)
	{
		*lst = addback;
		addback->prev = NULL;
		return ;
	}
	copy = last_node(*lst);
	copy->next = addback;
	addback->prev = copy;
}

//create a new list out of parameter **tab, check **tab for errors
t_env_list	*new_env_list(char **tab)
{
	int			a;
	t_env_list	*new_list;

	a = 0;
	new_list = NULL;
	while (tab[a + 1])
	{
		list_append(&new_list, tab[a]);
		a++;
	}
	return (new_list);
}

//bubble sort helper, swaps content of two nodes
void	content_swap(t_env_list *one, t_env_list *two)
{
	t_env_list	*temp;

	temp = (t_env_list *)malloc(sizeof(t_env_list));
	if (!temp)
		return ;
	temp->element = one->element;
	one->element = two->element;
	two->element = temp->element;
	free(temp);
}

//sorts a linked list in ascending order
void	bubble_sort(t_env_list **head)
{
	t_env_list	*a;
	t_env_list	*b;
	int		i;
	int		x;

	i = 0;
	while (i < list_size(*head))
	{
		a = get_node(*head, i);
		x = i + 1;
		while (x < list_size(*head))
		{
			b = get_node(*head, x);
			if (a->element[0] > b->element[0])
				content_swap(a, b);
			x++;
		}
		i++;
	}
}
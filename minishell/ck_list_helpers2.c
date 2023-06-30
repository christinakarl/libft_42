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
	int		i;

	i = 0;
	addback = (t_env_list *)malloc(sizeof(t_env_list));
	if (!addback)
		return ;
	addback->next = NULL;
	addback->element = ft_strdup(element);
	if (!addback->element)
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

// //detach last element from list
// void	list_detach(t_env_list **lst)
// {
// 	t_env_list	*last;

// 	last = last_node(*lst);
// 	while ((*lst)->next)
// 		*lst = (*lst)->next;
// 	(*lst)->next = NULL;
// 	last->prev = NULL;
// 	free(last->element);
// 	free(last);
// }

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
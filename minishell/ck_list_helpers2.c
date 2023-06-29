/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ck_list_helpers2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:04:19 by ckarl             #+#    #+#             */
/*   Updated: 2023/06/29 18:58:22 by ckarl            ###   ########.fr       */
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
	addback->element = element;
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
	while (tab[a])
	{
		if (tab[a + 1] == NULL)
			list_append(&new_list, "_=/usr/bin/env");
		else
			list_append(&new_list, tab[a]);
		a++;
	}
	return (new_list);
}
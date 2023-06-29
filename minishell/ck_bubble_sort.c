/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bubble_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:04:19 by ckarl             #+#    #+#             */
/*   Updated: 2023/06/29 18:54:01 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

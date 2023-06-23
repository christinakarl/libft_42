/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked-list-bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:44:21 by nvaubien          #+#    #+#             */
/*   Updated: 2023/05/23 01:52:04 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

t_list_pipex	*insert_at_tail(t_list_pipex *cmd, char *value)
{
	t_list_pipex	*new_node;
	t_list_pipex	*curr;

	new_node = ft_calloc(1, sizeof(new_node));
	new_node->value = value;
	new_node->next = NULL;
	if (cmd == NULL)
		return (new_node);
	else
	{
		curr = cmd;
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = new_node;
		return (cmd);
	}
}

void	free_list(t_list_pipex *head)
{
	t_list_pipex	*current;
	t_list_pipex	*next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free_node(current);
		current = next;
	}
}

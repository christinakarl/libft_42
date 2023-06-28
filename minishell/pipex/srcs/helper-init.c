/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper-init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 13:55:13 by nvaubien          #+#    #+#             */
/*   Updated: 2023/05/24 17:17:50 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	ft_len(char *s, int start, t_parsing *h)
{
	int	i;

	i = 0;
	if (s[start] == h->is_s_quotes || s[start] == h->is_d_quotes)
	{
		h->flag = 1;
		h->current_sep = s[start];
		start++;
		i++;
		while (s[start] && s[start] != h->current_sep)
		{
			start++;
			i++;
		}
		return (i);
	}
	else
	{
		while (s[start] && s[start] != h->is_space)
		{
			start++;
			i++;
		}
	}
	return (i);
}

t_list_pipex	*parse_cmds(int ac, char **av)
{
	t_list_pipex	*head;
	t_list_pipex	*tail;
	int				i;

	i = 2;
	head = NULL;
	tail = NULL;
	while (i < ac - 1)
	{
		if (head == NULL)
		{
			head = insert_at_tail(head, ft_substr(av[i], 0, ft_strlen(av[i])));
			tail = head;
		}
		else
		{
			tail = insert_at_tail(tail, ft_substr(av[i], 0, ft_strlen(av[i])));
		}
		i++;
	}
	return (head);
}

int	count_nodes(t_list_pipex *cmds)
{
	int	count;

	count = 0;
	while (cmds)
	{
		count++;
		cmds = cmds->next;
	}
	return (count);
}

char	***allocate_storage(t_list_pipex *cmds)
{
	int		i;
	char	***storage;

	i = count_nodes(cmds);
	storage = malloc(sizeof(char **) * i + 1);
	if (!storage)
		return (NULL);
	return (storage);
}

char	***commands_store(t_list_pipex *cmds, t_parsing *h)
{
	t_command_store_helper	*s;
	char					***to_exec;

	s = malloc(sizeof(t_command_store_helper));
	s->j = 0;
	to_exec = allocate_storage(cmds);
	while (cmds != NULL)
	{
		s->k = 0;
		s->start = 0;
		init_fields(cmds, h, to_exec, s->j);
		while (s->start < ft_strlen(cmds->value))
		{
			s->start = ft_start(cmds->value, s->start, h);
			s->len = ft_len(cmds->value, s->start, h);
			assign_to_exec(s, to_exec, cmds, h);
			s->start = s->start + s->len + 1;
			s->k++;
		}
		update_command_list(s, to_exec, &cmds);
	}
	free(s);
	return (to_exec);
}

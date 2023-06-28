/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper-init3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 14:53:04 by nvaubien          #+#    #+#             */
/*   Updated: 2023/05/20 18:15:52 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

char	**init_fields(t_list_pipex *cmds, t_parsing *h, char ***s, int i)
{
	s[i] = malloc(sizeof(char *) * c_fields(cmds->value, h) + 1);
	if (!s[i])
		return (NULL);
	return (s[i]);
}

void	update_command_list(t_command_store_helper *s,
	char ***to_exec, t_list_pipex **cmds)
{
	to_exec[s->j][s->k] = NULL;
	s->j++;
	*cmds = (*cmds)->next;
}

void	assign_to_exec(t_command_store_helper *s, char ***to_exec,
	t_list_pipex *cmds, t_parsing *h)
{
	if (h->flag == 1)
		to_exec[s->j][s->k] = ft_substr(cmds->value, s->start + 1, s->len - 1);
	else
		to_exec[s->j][s->k] = ft_substr(cmds->value, s->start, s->len);
}

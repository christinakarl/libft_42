/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper-init2-bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:37:25 by nvaubien          #+#    #+#             */
/*   Updated: 2023/05/23 01:48:51 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	init_helper(t_parsing *help)
{
	help->count = 0;
	help->is_space = ' ';
	help->is_d_quotes = '\"';
	help->is_s_quotes = '\'';
	help->flag = 0;
	help->current_sep = '\0';
	help->in_field = 0;
}

void	process_found_quote(char *s, t_parsing *h)
{
	if (h->flag == 0)
	{
		h->current_sep = *s;
		h->flag = 1;
		if (h->in_field == 0)
		{
			h->in_field = 1;
			h->count++;
		}
	}
	else if (h->current_sep == *s)
	{
		h->flag = 0;
		h->in_field = 0;
	}
}

void	process_in_field(t_parsing *h)
{
	if (h->in_field == 0)
	{
		h->in_field = 1;
		h->count++;
	}
}

int	c_fields(char *s, t_parsing *h)
{
	init_helper(h);
	while (*s)
	{
		if (*s == h->is_d_quotes || *s == h->is_s_quotes)
		{
			process_found_quote(s, h);
		}
		else if (*s != h->is_space && h->flag == 0)
		{
			process_in_field(h);
		}
		else if (h->flag == 0)
		{
			h->in_field = 0;
		}
		s++;
	}
	return (h->count);
}

int	ft_start(char *s, int start, t_parsing *h)
{
	init_helper(h);
	while (s[start] == h->is_space)
		start++;
	return (start);
}

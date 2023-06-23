/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory-handling-bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:45:20 by nvaubien          #+#    #+#             */
/*   Updated: 2023/05/25 13:33:38 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	free_command_store(t_pipex *pipex)
{
	size_t	i;
	int		j;

	i = 0;
	while (pipex->commands[i])
	{
		j = 0;
		while (pipex->commands[i][j] != NULL)
		{
			free(pipex->commands[i][j]);
			pipex->commands[i][j] = NULL;
			j++;
		}
		free(pipex->commands[i]);
		pipex->commands[i] = NULL;
		i++;
	}
	free(pipex->commands);
	pipex->commands = NULL;
}

void	free_ft_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		arr[i] = NULL;
		i++;
	}
	free(arr);
}

void	free_node(t_list_pipex *node)
{
	free(node->value);
	free(node);
}

void	free_all(t_pipex *pipex, char **arr)
{
	free_command_store(pipex);
	free_ft_split(arr);
	free(pipex->pipes);
	free(pipex);
}

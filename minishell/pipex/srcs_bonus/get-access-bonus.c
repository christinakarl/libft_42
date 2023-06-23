/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get-access-bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:34:42 by nvaubien          #+#    #+#             */
/*   Updated: 2023/05/22 15:35:03 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

char	*command_path_check(t_pipex *pipex, char **subdir, int no)
{
	int		i;
	char	*cmd;
	char	*path;

	i = 0;
	while (subdir[i])
	{
		path = ft_strjoin(subdir[i], "/");
		cmd = ft_strjoin(path, pipex->commands[no][0]);
		if (access(cmd, F_OK) == 0)
		{
			free(path);
			return (cmd);
		}
		i++;
		free(path);
		free(cmd);
	}
	return (NULL);
}

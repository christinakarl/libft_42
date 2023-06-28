/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get-access.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 02:33:08 by nvaubien          #+#    #+#             */
/*   Updated: 2023/05/21 20:56:02 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

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

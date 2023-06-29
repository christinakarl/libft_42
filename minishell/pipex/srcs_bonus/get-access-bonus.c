/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get-access-bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:34:42 by nvaubien          #+#    #+#             */
/*   Updated: 2023/06/29 13:41:11 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

//check if command exists & is executable
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
		if (access(cmd, F_OK & X_OK) == 0)
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

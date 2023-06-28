/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 11:59:02 by nvaubien          #+#    #+#             */
/*   Updated: 2023/05/22 16:17:39 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	init_pipex(int ac, char **av, t_pipex *pipex)
{
	t_list_pipex	*cmds;
	t_parsing		*help;

	help = malloc(sizeof(t_parsing));
	cmds = parse_cmds(ac, av);
	pipex->infile_name = av[1];
	pipex->outfile_name = av[ac - 1];
	pipex->file1_fd = get_infile_fd(pipex);
	pipex->file2_fd = get_outfile_fd(pipex);
	pipex->commands = commands_store(cmds, help);
	free_list(cmds);
	free(help);
}

char	**get_path_dir(char **envp)
{
	char	*path;
	char	**path_dirs;
	int		i;

	i = 0;
	path_dirs = NULL;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path = envp[i] + 5;
			path_dirs = ft_split(path, ':');
			if (!path_dirs)
			{
				perror("error");
				exit(1);
			}
			break ;
		}
		i++;
	}
	return (path_dirs);
}

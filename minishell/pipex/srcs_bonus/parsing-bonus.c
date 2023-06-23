/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing-bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:46:18 by nvaubien          #+#    #+#             */
/*   Updated: 2023/05/22 16:35:00 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	create_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->count_cmds)
	{
		improved_pipe(pipex->pipes + 2 * i);
		i++;
	}
}

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
	pipex->count_cmds = ac - 3;
	pipex->idx = 0;
	pipex->count_pipes = 2 * (pipex->count_cmds - 1);
	pipex->pipes = (int *)malloc(sizeof(int) * 2 * pipex->count_pipes);
	free_list(cmds);
	free(help);
	create_pipes(pipex);
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

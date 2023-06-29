/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing-bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:46:18 by nvaubien          #+#    #+#             */
/*   Updated: 2023/06/29 13:48:13 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

//create as many pipes as necessary
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

//init all fields of the t_pipex structure
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

//get the PATH from env as a char **
char	**get_path_dir(char **envp)
{
	char	*path;
	char	**path_dirs;

	while (*envp)
	{
		if (ft_strncmp(*envp, "PATH", 4) == 0)
			path = *envp;
		envp++;
	}
	path_dirs = ft_split((path + 5), ':');
	if (!path_dirs)
	{
		perror("error");
		exit(1);
	}
	return (path_dirs);
}


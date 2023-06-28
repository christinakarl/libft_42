/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:48:27 by nvaubien          #+#    #+#             */
/*   Updated: 2023/05/25 16:02:43 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	main(int ac, char **av, char **envp)
{
	char	**path_dirs;
	t_pipex	*pipex;

	if (ac != 5)
		return (msg(ERR_INPUT));
	pipex = malloc(sizeof(t_pipex));
	init_pipex(ac, av, pipex);
	path_dirs = get_path_dir(envp);
	pipe(pipex->tube);
	pipex->pid1 = improved_fork();
	if (pipex->pid1 == 0)
		first_child(pipex, path_dirs, envp);
	pipex->pid2 = improved_fork();
	if (pipex->pid2 == 0)
		second_child(pipex, path_dirs, envp);
	close_pipes(pipex);
	waitpid(pipex->pid1, NULL, 0);
	waitpid(pipex->pid2, NULL, 0);
	parent_free(pipex);
	free_all(pipex, path_dirs);
	return (0);
}

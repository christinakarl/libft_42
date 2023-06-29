/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main-bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:44:48 by nvaubien          #+#    #+#             */
/*   Updated: 2023/06/29 15:23:58 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

int	main(int ac, char **av, char **envp)
{
	char	**path_dirs;
	t_pipex	*pipex;

	if (ac < 5)
		return (msg(ERR_INPUT));
	pipex = malloc(sizeof(t_pipex));
	init_pipex(ac, av, pipex);
	path_dirs = get_path_dir(envp);
	while (pipex->idx < pipex->count_cmds)
	{
		child(pipex, path_dirs);
		pipex->idx++;
	}
	close_pipes(pipex);
	waitpid(-1, NULL, 0);
	parent_free(pipex);
	free_all(pipex, path_dirs);
	return (0);
}

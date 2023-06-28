/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 12:54:55 by nvaubien          #+#    #+#             */
/*   Updated: 2023/05/23 02:02:50 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

void	first_child(t_pipex *pipex, char **sub_dir, char **envp)
{
	char	*cmd;

	improved_dup2(pipex->tube[1], STDOUT_FILENO);
	close(pipex->tube[0]);
	improved_dup2(pipex->file1_fd, STDIN_FILENO);
	cmd = command_path_check(pipex, sub_dir, 0);
	if (cmd == NULL)
	{
		msg(ERR_CMD);
		exit(1);
	}
	execve(cmd, pipex->commands[0], envp);
}

void	second_child(t_pipex *pipex, char **sub_dir, char **envp)
{
	char	*cmd;

	dup2(pipex->tube[0], 0);
	close(pipex->tube[1]);
	dup2(pipex->file2_fd, 1);
	cmd = command_path_check(pipex, sub_dir, 1);
	if (cmd == NULL)
	{
		msg(ERR_CMD);
		exit(1);
	}
	execve(cmd, pipex->commands[1], envp);
}

void	close_pipes(t_pipex *pipex)
{
	close(pipex->tube[0]);
	close(pipex->tube[1]);
}

void	parent_free(t_pipex *pipex)
{
	close(pipex->file1_fd);
	close(pipex->file2_fd);
}

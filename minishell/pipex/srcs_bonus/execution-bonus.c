/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution-bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:32:19 by nvaubien          #+#    #+#             */
/*   Updated: 2023/05/25 13:33:11 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

void	close_pipes(t_pipex *pipex)
{
	int	i;

	i = 0;
	while (i < pipex->count_pipes)
	{
		close(pipex->pipes[i]);
		i++;
	}
}

void	sub_dup2(int zero, int first)
{
	improved_dup2(zero, 0);
	improved_dup2(first, 1);
}

void	parent_free(t_pipex *pipex)
{
	close(pipex->file1_fd);
	close(pipex->file2_fd);
}

void	child(t_pipex *p, char **envp)
{
	char	*cmd;

	p->pid = improved_fork();
	if (!p->pid)
	{
		if (p->idx == 0)
			sub_dup2(p->file1_fd, p->pipes[1]);
		else if (p->idx == p->count_cmds - 1)
			sub_dup2(p->pipes[2 * p->idx - 2], p->file2_fd);
		else
			sub_dup2(p->pipes[2 * p->idx - 2], p->pipes[2 * p->idx + 1]);
		close_pipes(p);
		cmd = command_path_check(p, envp, p->idx);
		if (!cmd)
		{
			msg(ERR_CMD);
			exit(1);
		}
		execve(cmd, p->commands[p->idx], envp);
	}
}

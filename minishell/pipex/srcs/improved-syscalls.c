/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   improved-syscalls.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 13:02:31 by nvaubien          #+#    #+#             */
/*   Updated: 2023/05/18 16:46:39 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	improved_dup2(int fildes, int fildes2)
{
	int	error;

	error = dup2(fildes, fildes2);
	if (error == -1)
	{
		perror("error dup2");
		exit(1);
	}
	return (error);
}

int	improved_pipe(int fd[2])
{
	int	error;

	error = pipe(fd);
	if (error == -1)
	{
		perror("error pipe");
		exit(1);
	}
	return (error);
}

pid_t	improved_fork(void)
{
	pid_t	error;

	error = fork();
	if (error == -1)
	{
		perror("error fork");
		exit(1);
	}
	return (error);
}

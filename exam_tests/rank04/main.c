/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:03:55 by ckarl             #+#    #+#             */
/*   Updated: 2023/11/14 12:46:09 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int	error_msg(char *str)
{
	int	i = -1;

	if (!str)
		return (1);
	while (str[++i])
	{
		write(2, &str[i], 1);
	}
	return (1);
}

int	cd_function(char **argv, int i)
{
	if (i != 2)
		return error_msg("error: cd: bad arguments\n");
	printf("%s\n", argv[1]);
	if (chdir(argv[1]) < 0)
		return error_msg("error: cd: cannot change directory to "), error_msg(argv[1]), error_msg("\n");
	return (0);
}

int	execve_function(char **argv, char **envp, int i)
{
	int		status = 0;
	pid_t	pid;
	int		fd[2];
	char	*needs_dup = NULL;

	if (argv[i] && !strcmp(argv[i], "|"))
		needs_dup = argv[i];
	if (pipe(fd) < 0 && needs_dup)
		return error_msg("error: fatal\n");
	pid = fork();
	if (pid < 0)
	{
		argv[i] = 0;
		if (needs_dup && (dup2(fd[1], STDIN_FILENO) < 0 || close(fd[0]) < 0 || close(fd[1]) < 0))
			return error_msg("error: fatal\n");
		execve(*argv, argv, envp);
		return error_msg("error: cannot execute "), error_msg(argv[0]), error_msg("\n");
	}
	waitpid(pid, &status, 0);
	if (needs_dup && (dup2(fd[0], STDOUT_FILENO) < 0 || close(fd[0]) < 0 || close(fd[1]) < 0))
			return error_msg("error: fatal\n");
	return WEXITSTATUS(status) && WIFEXITED(status);
}


int	main(int argc, char **argv, char **envp)
{
	int	status = 0;
	int	i = 0;

	if (argc == 2)
	{
		argv++;
		if (!strcmp(*argv, "cd"))
				status = cd_function(argv, i);
		else
			status = execve(*argv, argv, envp);
	}
	if (argc > 2)
	{
		while (argv[i] && argv[++i])
		{
			argv += i;
			i = 0;
			while (argv[i] && strcmp(argv[i], "|") && strcmp(argv[i], ";"))
				i++;
			if (!strcmp(*argv, "cd"))
				status = cd_function(argv, i);

			else
				status = execve_function(argv, envp, i);
			if (status == 1)
				break ;
		}
	}
	return (status);
}

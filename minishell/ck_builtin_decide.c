/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ck_builtin_decide.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:04:19 by ckarl             #+#    #+#             */
/*   Updated: 2023/06/30 15:56:51 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/* function assesses if argument is a built in*/
int	builtin_check(char *cmd)
{
	if (ft_strncmp(cmd, "echo", 4))
		return (1);
	else if (ft_strncmp(cmd, "cd", 2))
		return (1);
	else if (ft_strncmp(cmd, "pwd", 3))
		return (1);
	else if (ft_strncmp(cmd, "export", 6))
		return (1);
	else if (ft_strncmp(cmd, "unset", 5))
		return (1);
	else if (ft_strncmp(cmd, "env", 3))
		return (1);
	else if (ft_strncmp(cmd, "exit", 4))
		return (1);
	else
	return (0);
}

/*if yes, checks if there are given arguments
and redirects to right builtin function for execution*/
void	builtin_redirect(t_global **global, char *cmd, char *var)					//need to test this function
{
	if (ft_strncmp(cmd, "echo", 4))
		cmd_echo(cmd, var);
	else if (ft_strncmp(cmd, "cd", 2))
		cmd_cd(var);
	else if (ft_strncmp(cmd, "pwd", 3))
		cmd_pwd();
	else if (ft_strncmp(cmd, "export", 6))
	{
		if (!var)
			print_export((*global)->copy_env);
		else if (var)
			//add var to env list (no matter where, just not at the very end)
	}
	else if (ft_strncmp(cmd, "unset", 5))
		//take out var from env
	else if (ft_strncmp(cmd, "env", 3))
		print_env((*global)->copy_env);
	else if (ft_strncmp(cmd, "exit", 4))
		//exit & decrease SHLVL, if at 1, leave the programme
}
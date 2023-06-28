/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_ins.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:38:36 by ckarl             #+#    #+#             */
/*   Updated: 2023/06/22 16:31:20 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*The echo utility writes any specified operands, separated by single blank (` ')
characters and followed by a newline (`\n') character, to the standard output.
-n option: Do not print the trailing newline character. This may also be achieved
by appending `\c' to the end of the string, as is done by iBCS2 compatible systems.*/
void	cmd_echo(char **cmd, char *option)
{
	while (*cmd)
	{
		if (ft_strncmp(option, "-n", 2) == 0)
			ft_printf("%s", *cmd);
		else
			ft_printf("%s\n", *cmd);
		cmd++;
	}
}

/*cd with only a relative or absolute path*/
void	cmd_cd(char *to_go_path)
{
	chdir(to_go_path);
}

/*The pwd utility writes the absolute pathname of the current working directory
to the standard output.*/
void	cmd_pwd(void)
{
	ft_printf("%s\n", getcwd(NULL, 0));
}

/**/
void	cmd_export()
{

}

/**/
void	cmd_unset()
{

}

/*If no utility is specified, env prints out the names and values
of the variables in the environment, with one name/value pair per line.*/
void	cmd_env(char **env)
{
	while (*env)
	{
		ft_printf("%s\n", *env);
		env++;
	}
}

/**/
void	cmd_exit()
{

}



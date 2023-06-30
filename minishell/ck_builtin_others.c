/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ck_builtin_others.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:38:36 by ckarl             #+#    #+#             */
/*   Updated: 2023/06/30 15:26:44 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//ECHO WITH OPTION -N
/*The echo utility writes any specified operands, separated by single blank (` ')
characters and followed by a newline (`\n') character, to the standard output.
-n option: Do not print the trailing newline character.*/
void	cmd_echo(char **cmd, char *option)
{
	//check if var is in env table, if yes, need to print its value and not the var name
	while (*cmd)
	{
		if (ft_strncmp(option, "-n", 2) == 0)
			ft_printf("%s", *cmd);
		else
			ft_printf("%s\n", *cmd);
		cmd++;
	}
}

//CD WITH ONLY A RELATIVE OR ABSOLUTE PATH
/*The cd command in Linux is known as the change directory command.
It is used to move efficiently from the current working
directory to different directories in our System.*/
void	cmd_cd(char *to_go_path)
{
	chdir(to_go_path);
}

//PWD WITH NO OPTIONS
/*The pwd utility writes the absolute pathname of the current working directory
to the standard output.*/
void	cmd_pwd(void)
{
	ft_printf("%s\n", getcwd(NULL, 0));
}

//UNSET WITH NO OPTIONS
/*Using the unset command, you can unset values and attributes of shell								need to take it out of env table
variables.*/
void	cmd_unset(void *var)
{
	var = NULL;
}


//EXIT WITH NO OPTIONS
/*The exit() function causes normal process termination and the
least significant byte of status (i.e., status & 0xFF) is
returned to the parent (see wait(2)).*/
void	cmd_exit(int status)
{
	exit(status);
}



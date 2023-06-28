/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built-in.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:38:36 by ckarl             #+#    #+#             */
/*   Updated: 2023/06/28 16:29:19 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



//ECHO WITH OPTION -N
/*The echo utility writes any specified operands, separated by single blank (` ')
characters and followed by a newline (`\n') character, to the standard output.
-n option: Do not print the trailing newline character.*/
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

//EXPORT WITH NO OPTIONS
/*Normally, when you run a command at the bash prompt, a dedicated process is						needs more work, maybe global var?
created with its own environment, exclusively for running your command. Any
variables and functions you defined before running the command are not shared
with new processes — unless you explicitly mark them with export.
Example: myvar="This variable is defined." > export myvar > bash > echo $myvar >
"This variable is defined."*/
void	cmd_export(void *var)
{
	//need to add *var to env tableau
}

//UNSET WITH NO OPTIONS
/*Using the unset command, you can unset values and attributes of shell								need to take it out of env table
variables.*/
void	cmd_unset(void *var)
{
	var = NULL;
}

//ENV WITH NO OPTIONS OR ARGUMENTS
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

//EXIT WITH NO OPTIONS
/*The exit() function causes normal process termination and the
least significant byte of status (i.e., status & 0xFF) is
returned to the parent (see wait(2)).*/
void	cmd_exit(int status)
{
	exit(status);
}



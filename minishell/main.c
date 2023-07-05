/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:38:36 by ckarl             #+#    #+#             */
/*   Updated: 2023/07/05 17:30:50 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	(void)		argc;
	(void)		argv;
	// char		*read;
	t_global	global;
	char		**cmd = NULL;

	cmd[0] = "$myvar";
	cmd[1] = "5";

	// read = readline("minishell> ");
	global.copy_env = new_env_list(env);

	// add_var_export("myvar=6", &global.copy_env);
	// // print_env(global.copy_env);
	// print_export(global.copy_env);
	// add_var_export("myvar1=1", &global.copy_env);
	// // cmd_unset("myvar=$$mhallo", &global.copy_env);
	// printf("\n\n");
	// print_export(global.copy_env);

	cmd_echo(cmd, NULL, global.copy_env, true, false);

	return (0);
}
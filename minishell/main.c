/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:38:36 by ckarl             #+#    #+#             */
/*   Updated: 2023/07/05 17:52:59 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	(void)		argc;
	(void)		argv;
	(void)		env;
	char		*read;
	t_global	global;
	// char		*cmd[3] = {"myvar", "5"};



	// cmd[0] = "$myvar1";
	// cmd[1] = "5";
	// cmd[2] = NULL;
	global.copy_env = new_env_list(env);
	global.exit_status = 0;
	while (1)
	{
		read = readline("minishell> ");
		builtin_redirect((&global), read, NULL);

		// printf("%s\n", read);
		// cmd_cd("..");
		// cmd_pwd();
	}


	// add_var_export("myvar=6", &global.copy_env);
	// // print_env(global.copy_env);
	// print_export(global.copy_env);
	// add_var_export("myvar=1", &global.copy_env);
	// // cmd_unset("myvar=$$mhallo", &global.copy_env);
	// printf("\n\n");
	// print_export(global.copy_env);

	// printf("%s\n", cmd[0]);

	// cmd_echo(cmd, NULL, global.copy_env, true, false);

	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ck_builtin_echo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:38:36 by ckarl             #+#    #+#             */
/*   Updated: 2023/07/05 18:04:42 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//ECHO WITH OPTION -N
/*The echo utility writes any specified operands, separated by single blank (` ')
characters and followed by a newline (`\n') character, to the standard output.
-n option: Do not print the trailing newline character.*/

//return only the variable value from env
char	*trim_front(void *str, char sep)
{
	char	**copy;
	char	*trimmed;
	int		x;

	if (find_c(str, sep) == 0)
	{
		trimmed = ft_strdup((char *)str);
		return (str);
	}
	copy = ft_split((char *)str, sep);
	if (!copy)
		return (NULL);													//include error msg here
	trimmed = ft_strdup(copy[1]);
	x = -1;
	while (copy[++x])
		free (copy[x]);
	free(copy);
	return (trimmed);
}

//get variable value from env
char	*get_value(t_env_list *env, void *var)
{
	char	*value;
	int		len;

	len = ft_strlen((char *)var);
	while (env)
	{
		if (ft_strncmp(env->element, var, len) == 0)
			value = env->element;
		env = env->next;
	}
	return (value + len + 1);
}

/*check if var is in env table, if yes, need to print its value and not the var name,
check quotes ('$USER' should output $USER), inner and outer*/
void	cmd_echo(char **cmd, char *option, t_env_list *head, bool single_quotes, bool double_quotes)			//gives seg fault check why
{
	char	*print;
	char	*real_var;
	(void)	single_quotes;
	(void)	double_quotes;

	while (*cmd)
	{
		real_var = trim_front(*cmd, '$');
		if (existing_var_in_env(real_var, head) == true)			//need to check if $ is present, if yes trim it to find it in env and then print only value found in env
			print = trim_front(real_var, '=');
		else
			print = ft_strdup(*cmd);
		if (ft_strncmp(option, "-n", 2) == 0)
			ft_printf("%s", print);					//need to print % at the end like for cat
		else
			ft_printf("%s\n", print);
		free(print);
		cmd++;
	}
}
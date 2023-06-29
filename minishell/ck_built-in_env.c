/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built-in_env.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:38:36 by ckarl             #+#    #+#             */
/*   Updated: 2023/06/29 18:56:45 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//ENV WITH NO OPTIONS OR ARGUMENTS
/*If no utility is specified, env prints out the names and values
of the variables in the environment, with one name/value pair per line.*/

// char	**duplicate_env(char **env)
// {
// 	t_env_list	**copy;
// 	int		i;

// 	i = 0;
// 	copy = (char **)malloc(sizeof(*copy) * (tab_len(env) + 1));
// 	if (!copy)
// 		return (NULL);
// 	while (env[i])
// 	{
// 		copy[i] = ft_strdup(env[i]);
// 		i++;
// 	}
// 	copy[i] = 0;
// 	return (copy);
// }



void	print_env(char **env)
{
	t_env_list	*copy_env;

	copy_env = new_env_list(env);				//protect with a return
	if (!copy_env)
		printf("error duplicating\n");
	while (copy_env)
	{
		ft_printf("%s\n", copy_env->element);
		copy_env = copy_env->next;
	}
	//make sure to change level if "minishell" is called again
}

void	print_ascii_env(char **copy_env)
{
	t_env_list	*ascii_env;

	ascii_env = new_env_list(copy_env);				//protect with a return, check if this works correctly
	if (!ascii_env)
		printf("error duplicating\n");
	while (ascii_env)
	{
		ft_printf("%s\n", ascii_env->element);
		ascii_env = ascii_env->next;
	}

}

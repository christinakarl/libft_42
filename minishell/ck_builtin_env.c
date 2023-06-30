/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ck_builtin_env.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:38:36 by ckarl             #+#    #+#             */
/*   Updated: 2023/06/30 14:41:56 by ckarl            ###   ########.fr       */
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



void	print_env(t_env_list *copy_env)
{
	while (copy_env)
	{
		if (ft_strncmp(copy_env->element, "=", 100))			//if var is undefined, it should not be printed
			ft_printf("%s\n", copy_env->element);
		copy_env = copy_env->next;
	}
	ft_printf("_=/usr/bin/env\n");
	//make sure to change level if "minishell" is called again
}
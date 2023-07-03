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

//find character c in string s, similar to ft_strchr
int	find_c(char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

//print environment when command env is called
void	print_env(t_env_list *copy_env)
{
	while (copy_env)
	{
		if (find_c(copy_env->element, '='))			//if var is undefined, it should not be printed
			ft_printf("%s\n", copy_env->element);
		copy_env = copy_env->next;
	}
	ft_printf("_=/usr/bin/env\n");
	//make sure to change level if "minishell" is called again
}
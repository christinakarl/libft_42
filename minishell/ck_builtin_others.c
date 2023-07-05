/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ck_builtin_others.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 17:38:36 by ckarl             #+#    #+#             */
/*   Updated: 2023/07/05 17:08:20 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
/*Using the unset command, you can unset values and attributes of shell
variables.*/
void	cmd_unset(void *var, t_env_list **head)
{
	t_env_list	*list;
	t_env_list	*pre_copy;
	t_env_list	*post_copy;
	int			len;

	len = ft_strlen(var);
	list = *head;
	while (list)
	{
		if (ft_strncmp(list->element, var, len) == 0)
		{
			pre_copy = list->prev;
			post_copy = list->next;
			if (pre_copy)
				pre_copy->next = post_copy;
			if (post_copy)
				post_copy->prev = pre_copy;
			free(list->element);
			free(list);
		}
		list = list->next;
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



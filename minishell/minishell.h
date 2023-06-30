/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 12:26:53 by ckarl             #+#    #+#             */
/*   Updated: 2023/06/30 14:40:08 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>
# include "libs/ftprintf/ft_printf_utils.h"
# include "libs/libft/libft.h"
#include <readline/readline.h>
#include <readline/history.h>

typedef struct	s_env_list
{
	char				*element;
	struct s_env_list	*prev;
	struct s_env_list	*next;

}	t_env_list;

typedef struct	s_global
{
	t_env_list			*copy_env;

}	t_global;


void		cmd_echo(char **cmd, char *option);
void		cmd_cd(char *to_go_path);
void		cmd_pwd(void);;
void		cmd_export(void *var);
void		cmd_unset(void *var);
void		print_env(t_env_list *copy_env);
void		cmd_exit(int status);

/* linked list */
int			list_size(t_env_list *lst);
t_env_list	*last_node(t_env_list *lst);
t_env_list	*first_node(t_env_list *lst);
t_env_list	*get_node(t_env_list *head, int index);
t_env_list	*new_env_list(char **tab);
void		list_append(t_env_list **lst, char *element);
// void		list_detach(t_env_list **lst);

/* built-in: export */
void		content_swap(t_env_list *one, t_env_list *two);
void		bubble_sort(t_env_list **head);
void		print_export(t_env_list *ascii_env);




#endif

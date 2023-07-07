/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 12:26:53 by ckarl             #+#    #+#             */
/*   Updated: 2023/07/05 18:00:26 by ckarl            ###   ########.fr       */
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
# include <stdbool.h>
# include <errno.h>
# include "libs/ftprintf/ft_printf_utils.h"
# include "libs/libft/libft.h"
# include <readline/readline.h>
# include <readline/history.h>

typedef struct	s_env_list
{
	char				*element;
	struct s_env_list	*prev;
	struct s_env_list	*next;

}	t_env_list;

typedef struct	s_global
{
	t_env_list			*copy_env;
	int					exit_status;
}	t_global;

/* builtin_decide.c */
int		builtin_check(char *cmd);
void	builtin_redirect(t_global *global, char *cmd, char *var);


int			cmd_echo(char **cmd, char *option, t_env_list *head, bool single_quotes, bool double_quotes);
char		*get_value(t_env_list *env, void *var);
int			cmd_cd(char *to_go_path);
int			cmd_pwd(void);;
int			cmd_unset(void *var, t_env_list **head);
void		cmd_exit(int status);

/* builtin: env*/
int			find_c(char *str, char c);
int			print_env(t_env_list *copy_env);

/* linked list */
int			list_size(t_env_list *lst);
t_env_list	*last_node(t_env_list *lst);
t_env_list	*first_node(t_env_list *lst);
t_env_list	*get_node(t_env_list *head, int index);
t_env_list	*new_env_list(char **tab);
void		list_append(t_env_list **lst, char *element);
void		content_swap(t_env_list *one, t_env_list *two);
void		bubble_sort(t_env_list **head);

/* builtin: export */
int			check_var_format(void *var);
bool		existing_var_in_env(void *var, t_env_list *head);
char		*trim_back(void *var);
int			print_export(t_env_list *ascii_env);
int			add_var_export(void *var, t_env_list **head);





#endif

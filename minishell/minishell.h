/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 12:26:53 by ckarl             #+#    #+#             */
/*   Updated: 2023/06/28 15:01:22 by ckarl            ###   ########.fr       */
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

int			main(void);
void		cmd_echo(char **cmd, char *option);
void		cmd_cd(char *to_go_path);
void		cmd_pwd(void);;
static void	*cmd_export(void *var);
void		cmd_unset(void *var);
void		cmd_env(char **env);
void		cmd_exit(int status);






#endif

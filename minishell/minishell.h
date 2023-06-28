/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 12:26:53 by ckarl             #+#    #+#             */
/*   Updated: 2023/06/23 12:26:55 by ckarl            ###   ########.fr       */
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

void	cmd_echo(char **cmd, char *option);
void	cmd_cd(char *to_go_path);
int		main(void);






#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 14:39:00 by nvaubien          #+#    #+#             */
/*   Updated: 2023/05/24 16:55:41 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <errno.h>

# include <string.h>

# include "../libs/libft/libft.h"
# include "../libs/ftprintf/ft_printf.h"

# define ERR_INFILE "Infile"
# define ERR_OUTFILE "Outfile"
# define ERR_INPUT "Invalid number of arguments\n"
# define ERR_CMD "Command not found\n"

typedef struct s_command_store_helper
{
	size_t	start;
	int		len;
	int		j;
	int		k;
}	t_command_store_helper;

typedef struct s_parsing
{
	int		flag;
	int		count;
	int		in_field;
	char	is_space;
	char	is_s_quotes;
	char	is_d_quotes;
	char	current_sep;
}	t_parsing;

typedef struct s_pipex
{
	pid_t	pid;
	int		file1_fd;
	int		file2_fd;
	int		count_cmds;
	int		idx;
	int		count_pipes;
	int		*pipes;
	char	*infile_name;
	char	*outfile_name;
	char	***commands;
}	t_pipex;

typedef struct s_list_pipex
{
	char				*value;
	struct s_list_pipex	*next;
}	t_list_pipex;

/* --- error-handling-bonus.c --- */
int				msg(char *err);
void			msg_err(char *err);

/* --- execution-bonus.c --- */
void			close_pipes(t_pipex *pipex);
void			sub_dup2(int zero, int first);
void			child(t_pipex *p, char **envp);
void			parent_free(t_pipex *pipex);

/* --- file-handling-bonus.c --- */
int				get_infile_fd(t_pipex *pipex);
int				get_outfile_fd(t_pipex *pipex);

/* --- get-access-bonus.c --- */
char			*command_path_check(t_pipex *pipex, char **subdir, int no);

/* --- helper-init-bonus.c --- */
int				ft_len(char *s, int start, t_parsing *h);
t_list_pipex	*parse_cmds(int ac, char **av);
int				count_nodes(t_list_pipex *cmds);
char			***allocate_storage(t_list_pipex *cmds);
char			***commands_store(t_list_pipex *cmds, t_parsing *h);

/* --- helper-init2-bonus.c --- */
void			init_helper(t_parsing *help);
void			process_found_quote(char *s, t_parsing *h);
void			process_in_field(t_parsing *h);
int				c_fields(char *s, t_parsing *h);
int				ft_start(char *s, int start, t_parsing *h);

/* --- helper-init3-bonus.c --- */
char			**init_fields(t_list_pipex *cmds, t_parsing *h,
					char ***s, int i);
void			update_command_list(t_command_store_helper *s, char ***to_exec,
					t_list_pipex **cmds);
void			assign_to_exec(t_command_store_helper *s, char ***to_exec,
					t_list_pipex *cmds, t_parsing *h);

/* --- improved-syscalls-bonus.c --- */
int				improved_dup2(int fildes, int fildes2);
int				improved_pipe(int fd[2]);
pid_t			improved_fork(void);

/* --- linked-list-bonus.c --- */
t_list_pipex	*insert_at_tail(t_list_pipex *cmd, char *value);
void			free_list(t_list_pipex *head);
pid_t			improved_fork(void);

/* --- memory-handling-bonus.c --- */
void			free_command_store(t_pipex *pipex);
void			free_ft_split(char **arr);
void			free_all(t_pipex *pipex, char **arr);
void			free_node(t_list_pipex *node);

/* --- parsing-bonus.c --- */
void			create_pipes(t_pipex *pipex);
void			init_pipex(int ac, char **av, t_pipex *pipex);
char			**get_path_dir(char **envp);

/* --- main-bonus.c --- */
int				main(int ac, char **av, char **envp);

#endif
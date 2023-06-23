/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file-handling-bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 15:33:41 by nvaubien          #+#    #+#             */
/*   Updated: 2023/05/23 02:08:22 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex_bonus.h"

int	get_infile_fd(t_pipex *pipex)
{
	int	fd;

	fd = open(pipex->infile_name, O_RDONLY);
	if (fd < 0)
		msg_err(ERR_INFILE);
	return (fd);
}

int	get_outfile_fd(t_pipex *pipex)
{
	int		fd;
	mode_t	mode;

	mode = S_IRUSR | S_IWUSR;
	fd = open(pipex->outfile_name, O_WRONLY | O_CREAT | O_TRUNC, mode);
	if (fd < 0)
		perror("Cannot open outfile\n");
	return (fd);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error-handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvaubien <nvaubien@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 13:45:54 by nvaubien          #+#    #+#             */
/*   Updated: 2023/04/24 16:07:54 by nvaubien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pipex.h"

int	msg(char *err)
{
	write(2, err, ft_strlen(err));
	return (1);
}

void	msg_err(char *err)
{
	perror(err);
	exit(1);
}

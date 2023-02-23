/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 13:44:50 by ckarl             #+#    #+#             */
/*   Updated: 2023/01/04 18:40:14 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//use open() here in order to get file descriptor (int that uniquely identifies an open file of the process) for GNL function
//returns file descriptor used or -1 upon failure
int	main(void)
{
	int		fd;
	char	*gnl;

/*1. call*/	fd = open("text.txt", O_RDONLY);
			gnl = get_next_line(fd);
			printf("%s\n", gnl);
			free(gnl);

/*2. call*/	gnl = get_next_line(fd);
			printf("%s\n", gnl);
			free(gnl);
/*3. call*/	gnl = get_next_line(fd);
			printf("%s\n", gnl);
			free(gnl);
	//printf("%d\n", fd);
	close(fd);
	return (0);
}

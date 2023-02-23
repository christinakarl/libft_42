/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:47:55 by ckarl             #+#    #+#             */
/*   Updated: 2023/01/04 19:02:06 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//fd = file descriptor returned by open()

//check if string contains '\n'
int	checkcont(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

//add new item to linked list
int	add_new(c_list *head, int fd)
{
	c_list	*temp;
	c_list	*new;
	int		success;

	temp = head;

	while (checkcont(temp->content) == -1) //check if \n is included in current content
	{
		new = (c_list *)malloc(sizeof(new));									//leaking?
		if (new == NULL)
			return(-1);
		new->content = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
		if (new->content == NULL)
			return(-1);
		success = read(fd, new->content, BUFFER_SIZE);
		(new->content)[success] = '\0';
		new->next = NULL;
		temp->next = new;
		temp = temp->next;
	}
	free(temp);
	return(success);
}

int	list_len(c_list *head)
{
	int	i;

	i = 0;
	while (head != 0)
	{
		i++;
		head = head->next;
	}
	return (i);
}

char	*get_next_line(int fd)
{
	static c_list		*head;
	c_list				*temp;
	char				*final;
	int					a;
	int					b;

	a = 0;
	head = (c_list *)malloc(sizeof(head));
	if (head == NULL)
		return (NULL);

	head->content = (char *)malloc(sizeof(char) * BUFFER_SIZE); //read first time
	if (head == NULL)
		return(NULL);
	read(fd, head->content, BUFFER_SIZE);
	head->next = NULL;

	add_new(head, fd);
	temp = head;

	printf("%d\n", list_len(head));

	final = (char *)malloc(sizeof(char) * (BUFFER_SIZE * list_len(head) + 1));
	if (final == 0)
		return(NULL);

	while (temp != 0)						//need to delete everything that was copied into final (including \n)
	{
		b = 0;
		while (temp->content[b])
		{
			if (temp->content[b] == '\n')
			{
				final[a++] = temp->content[b];
				break;
			}
			final[a++] = temp->content[b++];
		}
		temp = temp->next;
	}
//	if (final[a - 1] != '\n')
//		final[a++] = '\n';
	final[a] = '\0';
	free(temp);
	return (final);
}
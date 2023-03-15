/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:34:49 by ckarl             #+#    #+#             */
/*   Updated: 2023/03/02 11:34:51 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

//CHECK IF STRING (CONTENT) CONTAINS '\N'
int	checkcont(t_list *list)
{
	int		i;
	t_list	*temp;

	i = 0;
	if (!list)
		return (0);
	temp = ft_lastitem(list);
	while (temp->content[i])
	{
		if (temp->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

//FIND LAST ITEM OF LINKED LIST
t_list	*ft_lastitem(t_list *lst)
{
	t_list	*inter;

	if (lst == NULL)
		return (lst);
	inter = lst;
	while (inter->next != NULL)
		inter = inter->next;
	return (inter);
}

//ADD NEW ITEM AND ADD IT TO LINKED LIST
void	ft_lstadd_back(t_list **lst, char *buf, int success)
{
	t_list	*addback;
	t_list	*copy;
	int		i;

	i = 0;
	addback = (t_list *)malloc(sizeof(t_list));
	if (!addback)
		return ;
	addback->next = NULL;
	addback->content = (char *)malloc(success + 1);
	if (addback->content == NULL)
		return ;
	while (buf[i] && i < success)
	{
		addback->content[i] = buf[i];
		i++;
	}
	addback->content[i] = '\0';
	if (*lst == NULL)
	{
		*lst = addback;
		return ;
	}
	copy = ft_lastitem(*lst);
	copy->next = addback;
}

//CREATE LINKED LIST UNTIL ELEMENT CONTENT CONTAINS '\N'
void	ft_getlist(t_list **lst, int fd)
{
	char	*buf;
	int		success;

	success = -1;
	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (!buf)
		return ;
	while (checkcont(*lst) == 0 && success != 0)
	{
		success = read(fd, buf, BUFFER_SIZE);
		if (success == -1)
		{
			free(buf);
			return ;
		}
		buf[success] = '\0';
		ft_lstadd_back(lst, buf, success);
	}
	free(buf);
}

//return the line to main (possible from multiple fds)
char	*get_next_line(int fd)
{
	static t_list	*list[500];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
	{
		if (fd >= 0)
			clear_list(&list[fd]);
		return (NULL);
	}
	ft_getlist(&list[fd], fd);
	if (!list[fd])
		return (NULL);
	ft_getline(&line, list[fd]);
	new_list(&list[fd]);
	if (line[0] == '\0')
	{
		if (fd >= 0)
			clear_list(&list[fd]);
		free(line);
		return (NULL);
	}
	return (line);
}

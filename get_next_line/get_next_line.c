/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:47:55 by ckarl             #+#    #+#             */
/*   Updated: 2023/02/24 14:36:47 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

//CHECK IF STRING (CONTENT) CONTAINS '\N'
int	checkcont(c_list *list)
{
	int		i;
	c_list	*temp;

	i = 0;
	if (!list)
		return (0);
	temp = ft_lstlast(list);
	while (temp->content[i])
	{
		if (temp->content[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

//FIND LAST ITEM OF LINKED LIST
c_list	*ft_lstlast(c_list *lst)
{
	c_list	*inter;

	if (lst == NULL)
		return (lst);
	inter = lst;
	while (inter->next != NULL)
		inter = inter->next;
	return (inter);
}

//ADD NEW ITEM AND ADD IT TO LINKED LIST
void	ft_lstadd_back(c_list **lst, char *buf, int success)
{
	c_list	*addback;
	c_list	*copy;
	int		i;

	i = 0;
	addback = (c_list *)malloc(sizeof(c_list));
	if (!addback)
		return ;
	addback->next = NULL;
	addback->content = (char *)malloc(sizeof(char)*(success + 1));
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
	copy = ft_lstlast(*lst);
	copy->next = addback;
}

//CREATE LINKED LIST UNTIL ELEMENT CONTENT CONTAINS '\N'
void	ft_getlist(c_list **lst, int fd)
{
	char	*buf;
	int		success;

	success = -1;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
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

//return the line to main
char	*get_next_line(int fd)
{
	static c_list	*list;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);

	ft_getlist(&list, fd);
	if (!list)
		return (NULL);

	ft_getline(&line, list);

	new_list(&list);

	if (line[0] == '\0')
	{
		clear_list(&list);
		free(line);
		return (NULL);
	}
	return (line);
}


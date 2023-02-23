/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:47:55 by ckarl             #+#    #+#             */
/*   Updated: 2023/01/04 19:02:06 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "gnl.h"

/*check if string (content) contains '\n'*/
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

/*find last item of linked list*/
c_list	*ft_lstlast(c_list *lst)
{
	c_list	*inter;

	inter = lst;
	while (inter->next != NULL)
		inter = inter->next;
	return (inter);
}

/*create new item for linked list
c_list	*ft_lstnew(char **buf)
{
	c_list	*new;

	new = (c_list *)malloc(sizeof(c_list));
	if (!new)
		return (NULL);
	new->content = buf;
	new->next = NULL;
	return (new);
}*/

/*add new item to linked list*/
void	*ft_lstadd_back(c_list **lst, char *buf, int success)
{
	c_list	*addback;
	c_list	*copy;
	int		i;

	i = 0;
	addback = (c_list *)malloc(sizeof(c_list));
	if (!addback)
		return (NULL);
	addback->next = NULL;
	addback->content = (char *)malloc(sizeof(char)*(success + 1));
	if ((addback->content) == NULL)
		return 0;
	while (buf[i] && i < success)
	{
		addback->content[i] = buf[i];
		i++;
	}
	addback->content[i] = '\0';
	if (*lst == NULL)
	{
		*lst = addback;
		return 0;
	}
	copy = ft_lstlast(*lst);
	copy->next = addback;
}

/*create linked list until content contains '\n'*/
void	*ft_getlist(c_list **lst, int fd)
{
	char	*buf;
	int		success;

	success = 1;
	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while (checkcont(buf) == -1 && success != 0)
	{
		success = read(fd, buf, BUFFER_SIZE);
		if (success == -1)
		{
			free(buf);
			return 0;
		}
		buf[success] = '\0';
		ft_lstadd_back(lst, buf, success);
	}
	free(buf);
}

/*return the line to main*/
char	*get_next_line(int fd)
{
	static c_list	*list;
	c_list			*inter;
	char			*line;
	int				size;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	ft_getlist(&list, fd);
	if (!list)
		return (NULL);
	inter = list;
	while (inter != 0)
	{
		printf("%s\n", inter->content);
		inter = inter->next;
	}
	ft_getline(&line, list);
	printf("%s\n", line);

	size = ft_lstsize(list);
	printf("%d\n", size);



	return (line);
}

		/*while (list != 0)
	{
		printf("%s\n", list->content);
		list = list->next;
	}*/


	//printf("%s\n", (*lst)->content);
	//*lst = (*lst)->next;

	/*list = (c_list *)malloc(sizeof(c_list));
	if (!list)
		return (NULL);
	list->next = NULL;*/

		//	printf("%s\n", (inter)->content);
		//(inter) = (inter)->next;

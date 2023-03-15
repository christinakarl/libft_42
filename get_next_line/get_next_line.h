/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:48:07 by ckarl             #+#    #+#             */
/*   Updated: 2023/03/15 11:57:43 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct node
{
	char			*content;
	struct node		*next;
}	t_list;

char	*get_next_line(int fd);
int		ft_lstsize(t_list *lst);
void	ft_getlist(t_list **lst, int fd);
void	ft_lstadd_back(t_list **lst, char *buf, int success);
int		checkcont(t_list *list);
t_list	*ft_lastitem(t_list *lst);
void	ft_getline(char **line, t_list *list);
void	clear_list(t_list **list);
void	new_list(t_list **list);

#endif

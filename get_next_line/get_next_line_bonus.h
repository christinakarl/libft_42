/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 11:35:55 by ckarl             #+#    #+#             */
/*   Updated: 2023/03/15 11:58:31 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

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

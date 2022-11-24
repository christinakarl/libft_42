/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <marvin@42lausanne.ch>               +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 13:03:11 by ckarl             #+#    #+#             */
/*   Updated: 2022/10/27 14:20:08 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*list;

	list = NULL;//so that lstadd_back puts new at the first place and works correctly
	while (lst)
	{
		new = ft_lstnew(f(lst));
		if (!new)
		{
			ft_lstclear(new, del);//puts lst = NULL, deletes all elements of the list
			return (lst);
		}
		ft_lstadd_back(&list, new);//& because we need a double pointer
		lst = lst->new;
	}
	return (list);
	}
}
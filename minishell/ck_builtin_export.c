/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ck_builtin_export.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ckarl <ckarl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 15:04:19 by ckarl             #+#    #+#             */
/*   Updated: 2023/06/30 15:17:34 by ckarl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

//EXPORT WITH NO OPTIONS (BUT WITH POTENTIAL ARGUMENTS)
/*Normally, when you run a command at the bash prompt, a dedicated process is
created with its own environment, exclusively for running your command. Any
variables and functions you defined before running the command are not shared
with new processes — unless you explicitly mark them with export.
Example: myvar="This variable is defined." > export myvar > bash > echo $myvar >
"This variable is defined."*/
void	cmd_export(void *var)
{
	(void) *var;
	//need to add *var to env tableau
}

//cmd: export (without args), prints env in ascii order without the last arg path
void	print_export(t_env_list *env_for_export)
{
	char	**lines;

	//check if last history was "minishell", if yes, add line list_append() with "_="/bin/bash""
	bubble_sort(&env_for_export);
	while (env_for_export)
	{
		lines = (char **)malloc(sizeof(char *) * 3);
		if (!lines)
			return ;												//include error msg here
		lines = ft_split(env_for_export->element, '=');
		if (!lines)
			return ;												//include error msg here
		ft_printf("declare -x %s=%c%s%c\n", lines[0], '"', lines[1], '"');
		env_for_export = env_for_export->next;
		free(lines[0]);
		free(lines[1]);
		free(lines);
	}
}

//bubble sort helper, swaps content of two nodes
void	content_swap(t_env_list *one, t_env_list *two)
{
	t_env_list	*temp;

	temp = (t_env_list *)malloc(sizeof(t_env_list));
	if (!temp)
		return ;
	temp->element = one->element;
	one->element = two->element;
	two->element = temp->element;
	free(temp);
}

//sorts a linked list in ascending order
void	bubble_sort(t_env_list **head)
{
	t_env_list	*a;
	t_env_list	*b;
	int		i;
	int		x;

	i = 0;
	while (i < list_size(*head))
	{
		a = get_node(*head, i);
		x = i + 1;
		while (x < list_size(*head))
		{
			b = get_node(*head, x);
			if (a->element[0] > b->element[0])
				content_swap(a, b);
			x++;
		}
		i++;
	}
}


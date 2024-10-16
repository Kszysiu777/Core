/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_b.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbizon <kbizon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:32:39 by kbizon            #+#    #+#             */
/*   Updated: 2024/10/12 17:32:49 by kbizon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack_b	*create_list_b(int argc, char **argv)
{
	int			i;
	t_stack_b	*head_b;
	t_stack_b	*tmp;

	i = 1;
	head_b = ft_newnode_b(ft_atoi(argv[i]));
	tmp = head_b;
	while (++i < argc)
	{
		tmp->next = ft_newnode_b(ft_atoi(argv[i]));
		tmp = tmp->next;
		tmp->next = NULL;
	}
	return (head_b);
}

t_stack_b	*ft_newnode_b(int content)
{
	t_stack_b	*ptr;

	ptr = (t_stack_b *)malloc(sizeof(t_stack_b));
	if (!ptr)
		return (NULL);
	ptr->content = content;
	ptr->next = NULL;
	return (ptr);
}

void	ft_clearnodes_b(t_stack_b **lst)
{
	t_stack_b	*ptr;

	while (*lst != NULL)
	{
		ptr = *lst;
		*lst = ptr->next;
		free(ptr);
	}
}

int	ft_listsize_b(t_stack_b *head)
{
	int	count;

	count = 0;
	while (head != NULL)
	{
		count++;
		head = head->next;
	}
	return (count);
}

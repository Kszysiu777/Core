/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_max_min_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbizon <kbizon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:13:20 by kbizon            #+#    #+#             */
/*   Updated: 2024/10/12 18:13:27 by kbizon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_max_min_b(t_stacks *stacks)
{
	if (stacks->head_b != NULL)
	{
		check_max_b(stacks, stacks->head_b);
		check_min_b(stacks, stacks->head_b);
	}
}

void	check_min_b(t_stacks *stacks, t_stack_b *head_b)
{
	int	i;
	int	size;

	i = 0;
	size = ft_listsize_b(head_b);
	stacks->values->min_b = head_b->content;
	while (i < size)
	{
		if (stacks->values->min_b > head_b->content)
			stacks->values->min_b = head_b->content;
		head_b = head_b->next;
		i++;
	}
}

void	check_max_b(t_stacks *stacks, t_stack_b *head_b)
{
	int	i;
	int	size;

	i = 0;
	size = ft_listsize_b(head_b);
	stacks->values->max_b = head_b->content;
	while (i < size)
	{
		if (stacks->values->max_b < head_b->content)
			stacks->values->max_b = head_b->content;
		head_b = head_b->next;
		i++;
	}
}

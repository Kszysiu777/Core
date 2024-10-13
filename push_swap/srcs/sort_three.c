/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbizon <kbizon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:50:53 by kbizon            #+#    #+#             */
/*   Updated: 2024/10/12 17:50:59 by kbizon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stacks *stacks, int flag)
{
	t_stack_a	*head_a;
	int			num1;
	int			num2;
	int			num3;

	head_a = stacks->head_a;
	num1 = head_a->content;
	num2 = head_a->next->content;
	num3 = head_a->next->next->content;
	identify_nums_three(stacks, num1, num2, num3);
	if (flag)
	{
		ft_clearnodes_a(&stacks->head_a);
		exit(0);
	}
}

void	identify_nums_three(t_stacks *stacks, int num1, int num2, int num3)
{
	if (num1 > num2 && num1 < num3 && num2 < num3)
		ft_swap(stacks, 'a');
	else if (num1 > num2 && num1 > num3 && num2 < num3)
		ft_rotate(stacks, 'a');
	else if (num1 < num2 && num1 > num3 && num2 > num3)
		ft_rev_rotate(stacks, 'a');
	else if (num1 > num2 && num1 > num3 && num2 > num3)
	{
		ft_swap(stacks, 'a');
		ft_rev_rotate(stacks, 'a');
	}
	else if (num1 < num2 && num1 < num3 && num2 > num3)
	{
		ft_swap(stacks, 'a');
		ft_rotate(stacks, 'a');
	}
}

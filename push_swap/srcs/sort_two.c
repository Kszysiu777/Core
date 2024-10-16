/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbizon <kbizon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:37:30 by kbizon            #+#    #+#             */
/*   Updated: 2024/10/12 17:37:39 by kbizon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stacks *stacks)
{
	ft_swap(stacks, 'a');
	ft_clearnodes_a(&stacks->head_a);
	exit(0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbizon <kbizon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 18:10:11 by kbizon            #+#    #+#             */
/*   Updated: 2024/10/12 18:10:17 by kbizon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_for_all(t_stacks *stacks)
{
	ft_clearnodes_a(&stacks->head_a);
	ft_clearnodes_b(&stacks->head_b);
	free(stacks->values);
	free(stacks->moves);
	free(stacks->cheap);
}

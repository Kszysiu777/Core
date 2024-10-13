/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbizon <kbizon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 16:48:51 by kbizon            #+#    #+#             */
/*   Updated: 2024/10/12 17:06:12 by kbizon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stacks	stacks;

	input_error(argc, argv);
	stacks.head_a = create_list_a(argc, argv);
	stacks.head_b = NULL;
	check_for_doubles(stacks.head_a);
	sorting(&stacks);
	free_for_all(&stacks);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbizon <kbizon@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/12 17:05:06 by kbizon            #+#    #+#             */
/*   Updated: 2024/10/12 17:06:06 by kbizon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	input_error(int argc, char **argv)
{
	if (argc == 1)
		exit(0);
	check_integers(argc, argv);
	check_int_size(argc, argv);
}

void	check_integers(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (argv[i][j] == '\0')
			print_error_and_exit();
		while (j < (int)ft_strlen(argv[i]))
		{
			if (!ft_isdigit(argv[i][j]))
			{
				if (j == 0 && ft_strlen(argv[i]) != 1 && \
					(argv[i][j] == '-' || argv[i][j] == '+'))
				{
					j++;
					continue ;
				}
				print_error_and_exit();
			}
			j++;
		}
		i++;
	}
}

void	check_int_size(int argc, char **argv)
{
	long	num;
	int		i;

	i = 1;
	while (i < argc)
	{
		num = ft_atol(argv[i]);
		if (num > INTMAX || num < INTMIN)
			print_error_and_exit();
		i++;
	}
}

void	check_for_doubles(t_stack_a *head_a)
{
	t_stack_a	*tmp;
	t_stack_a	*ptr;
	int			num;

	ptr = head_a;
	while (ptr != NULL)
	{
		tmp = ptr;
		num = tmp->content;
		tmp = tmp->next;
		while (tmp != NULL)
		{
			if (num == tmp->content)
			{
				ft_putstr_fd("Error\n", 2);
				ft_clearnodes_a(&head_a);
				exit(0);
			}
			tmp = tmp->next;
		}
		ptr = ptr->next;
	}
}

void	print_error_and_exit(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(0);
}

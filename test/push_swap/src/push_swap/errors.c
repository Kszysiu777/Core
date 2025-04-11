# include "../../inc/push_swap.h"

void	error_free(t_stack_node **a, char argv[][], bool flag_argc_2)
{
	free_stack(a);
	if (flag_argc_2)
		free_arg(argv);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*temp;
	t_stack_node	*current;

	if (NULL == stack)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
	*stack = NULL;
}

void	free_arg(char **argv)
{
	int	i;

	i = -1;
	if (NULL == argv || NULL == *argv)
		return ;
	while (argv[i])
		free(argv[i++]);
	free(argv - 1);
}

int		error_syntax(char *str_num)
{
	if (!(*str_num == '+' || *str_num == '-'
			|| (*str_num >= '0' && *str_num <= '9')))
		return (true);
	if ((*str_num == '+'|| *str_num == '-')
		&& !(str_num[1] >= '0' && str_num[1] <= '9'))
		return (true);
	while (*++str_num)
	{
		if (!(*str_num >= '0' && *str_num <= '9'))
			return (true);
	}
	return (false);
}

int		error_repetition(t_stack_node *a, int num)
{
	if (NULL == a)
		return (false);
	while (a)
	{
		if (a->value == num)
			return (true);
		a = a->next;
	}
	return (false);
}


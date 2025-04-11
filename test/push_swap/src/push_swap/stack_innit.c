# include "../../inc/push_swap.h"

void	stack_innit(t_stack_node **a, char argv[][], bool flag_argc_2)
{
	long	num;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			error_free(a, argv, flag_argc_2);
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
			error_free(a, argv, flag_argc_2);
		if (error_repetition(*a, (int)num))
			error_free(a, argv, flag_argc_2);
		append_node(a, (int)num);
		i++;
	}
	if (flag_argc_2)
		free_arg(argv);
}

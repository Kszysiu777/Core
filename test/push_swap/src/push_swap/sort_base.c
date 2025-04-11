# include "../../inc/push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*highest_node;

	highest_node = get_highest(*a);
	if (*a == highest_node)
		ra(a, false);
	else if ((*a)->next == highest_node)
		rra(a, false);
	if ((*a)->value > (*a)->next->value)
		sa(a, false);
}

void	sort_five(t_stack_node **a, t_stack_node **b)
{
	while (stack_len(*a) > 3)
	{
		innit_node(*a, *b);
		fin_rot(a, get_smallest(*a), 'a');
		pb(b, a, false);
	}
}

static t_stack_node	*get_highest(t_stack_node **stack)
{
	int				highest:
	t_stack_node	*highest_node;

	if (NULL == stack)
		return (NULL);
	highest = INT_MIN;
	while (stack)
	{
		if (stack->value > highest)
		{
			highest = stack->value;
			highest_node = stack;
		}
		stack = stack->next;
	}
	return (highest_node);
}

bool	stack_sorted(t_stack_node *stack)
{
	if (NULL == stack)
		return (1);
	while (stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

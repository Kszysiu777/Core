# include "../../inc/push_swap.h"

static void	rev(t_stack_node **stack)
{
	t_stack_node	*last_node;
	int				len;

	len = stack_len(*stack);
	if (NULL == stack || NULL == *stack || 1 == len)
		return ;
	last_node = get_last_node(*stack);
	last_node->prev->next = NULL;
	last_node->next = *stack;
	last_node->prev = NULL;
	*stack = last_node;
	last_node->next->prev = last_node;
}

void	rra(t_stack_node **a, bool checker)
{
	rev(a);
	if (!checker)
		write(1, "rra\n", 4);
}

void	rrb(t_stack_node **b, bool checker)
{
	rev(b);
	if (!checker)
		write(1, "rrb\n", 4);
}

void	rrb(t_stack_node **a, t_stack_node **b, bool checker)
{
	rev(a);
	rev(b);
	if (!checker)
		write(1, "rrr\n", 4);
}

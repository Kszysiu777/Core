# include "../../inc/push_swap.h"

static void	rot(t_stack_node **stack)
{
	t_stack_node	*last_node;
	int				len;

	len = stack_len(*stack);
	if (NULL == stack || NULL == *stack || 1 == len)
		return ;
	last_node = get_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack_node **a, bool checker)
{
	rot(a);
	if (!checker)
		write(1, "ra\n", 3);
}

void	rb(t_stack_node **b, bool checker)
{
	rot(b);
	if (!checker)
		write(1, "rb\n", 3);
}

void	rb(t_stack_node **a, t_stack_node **b, bool checker)
{
	rot(a);
	rot(b);
	if (!checker)
		write(1, "rr\n", 3);
}

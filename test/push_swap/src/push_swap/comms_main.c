# include "../../inc/push_swap.h"

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*smallest;
	int				lenA;

	lenA = stack_len(*a);
	if (lenA == 5)
		sort_five(a, b);
	else
	{
		while (lenA-- > 3)
			pb(b, a, false);
	}
	sort_three(a);
	while (*b)
	{
		innit_nodes(*a, *b);
		move_nodes(a, b);
	}
	set_current_position(*a);
	smallest = get_smallest(*a);
	if (smallest->above_median)
		while (*a != smallest)
			ra(a, false);
	else
		while (*a != smallest)
			rra(a, false);
}

static void	move_nodes(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*cheapest_node;

	cheapest_node = get_cheapest(*b);
	if (cheapest_node->above_median
		&& cheapest_node->target_node->above_median)
		rot_both(a, b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target_node->above_median)
		rev_rot_both(a, b, cheapest_node);
	finish_rotation(b, cheapest_node, 'b');
	finish_rotation(a, cheapest_node->target_node, 'a');
	pa(a, b, false);

	static void	rot_both(t_stack_node **a,
				t_stack_node **b, t_stack_node *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rr(a, b, false);
	set_current_position(*a);
	set_current_position(*b);
}

	static void	rev_rot_both(t_stack_node **a,
				t_stack_node **b, t_stack_node *cheapest_node)
{
	while (*a != cheapest_node->target_node && *b != cheapest_node)
		rrr(a, b, false);
	set_current_position(*a);
	set_current_position(*b);
}

void	finish_rotation(t_stack_node **stack, t_stack_node *top, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top->above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if (stack_name == 'b')
		{
			if (top->above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}

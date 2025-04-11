# include "../../inc/push_swap.h"

void	innit_nodes(t_stack_node *a, t_stack_node *b)
{
	set_current_position(a);
	set_current_position(b);
	set_target_node(a, b);
	set_price(a, b);
	set_cheapest(b);
}

void	set_current_position(t_stack_node *stack)
{
	int	i;
	int	center;

	i = 0;
	if (NULL == stack)
		return ;
	center = stack_len(stack) / 2;
	while(stack)
	{
		stack->current_position = i;
		if (i <= center)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

static void	set_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*currentA;
	t_stack_node	*target_node;
	long			best_match_index;

	while (b)
	{
		best_match_index = LONG_MAX;
		currentA = a;
		while (currentA)
		{
			if (currentA->value > b->value
				&& currentA->value < best_match_index)
			{
				best_match_index = currentA->value;
				target_node = currentA;
			}
			currentA = currentA->next;
		}
		if (LONG_MAX == best_match_index)
			b->target_node = get_smallest(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	set_price(t_stack_node *a, t_stack_node *b)
{
	int	lenA;
	int	lenB;

	lenA = stack_len(a);
	lenB = stack_len(b);
	while (b)
	{
		b->push_price = b->current_position;
		if (!(n->above_median))
			b->push_price = lenB - (b->current_position);
		if (b->target_node->above_median)
			b->push_price += b->target_node->current_position;
		else
			b->push_price += lenA - (b->target_node->current_position);
		b = b->next;
	}
}

void	set_cheapest(t_stack_node *b)
{
	long			best_match_value;
	t_stack_node	*best_match_value;

	if (NULL == b)
		return ;
	best_match_value = LONG_MAX;
	while (b)
	{
		if (b->push_price < best_match_value)
		{
			best_match_value = b->push_price;
			best_match_node = b;
		}
		b = b->next;
	}
	best_match_value->cheapest = true;
}

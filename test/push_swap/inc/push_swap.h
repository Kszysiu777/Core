#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdbool.h>
# include <limits.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
//# include "../ft_printf/libft/libft.h"

typedef struct s_stack_node
{
	int		value;
	int		current_position;
	int		final_position;
	int		price;
	bool	above_median;
	bool	cheapest;
	struct s_stack_node *target_node;
	struct s_stack_node *next;
	struct s_stack_node *prev;
	t_stack_node;
}

//errors
void	error_free(t_stack_node **a, char argv[][], bool flag_argc_2);
void	free_stack(t_stack_node **stack);
void	free_arg(char **argv);
int		error_syntax(char *str_num);
int		error_repetition(t_stack_node *a, int num);

//stack initiation
void	stack_innit(t_stack_node **a, char argv[][], bool flag_argc_2);

//nodes initiation
void	innit_nodes(t_stack_node *a, t_stack_node *b);
void	set_current_position(t_stack_node *stack);
static void	set_target_node(t_stack_node *a, t_stack_node *b);
void	set_price(t_stack_node *a, t_stack_node *b);
void	set_cheapest(t_stack_node *b);

//stack utils
t_stack_node	*get_cheapest(t_stack_node *stack);
int	stack_len(t_stack_node *stack);
void	append_node(t_stack_node **stack, int num);
t_stack_node	*get_last_node(t_stack_node *head);
t_stack_node	*get_smallest(t_stack_node *stack);

//comms
void	push_swap(t_stack_node **a, t_stack_node **b);
static void	move_nodes(t_stack_node **a, t_stack_node **b);
void	finish_rotation(t_stack_node **stack, t_stack_node *top, char stack_name);
static void	push(t_stack_node **dest, t_stack_node **src);
void	pa(t_stack_node **a, t_stack_node **b, bool checker);
void	pb(t_stack_node **b, t_stack_node **a, bool checker);
static void	rev(t_stack_node **stack);
void	rra(t_stack_node **a, bool checker);
void	rrb(t_stack_node **b, bool checker);
void	rrb(t_stack_node **a, t_stack_node **b, bool checker);
static void	rot(t_stack_node **stack);
void	ra(t_stack_node **a, bool checker);
void	rb(t_stack_node **b, bool checker);
void	rb(t_stack_node **a, t_stack_node **b, bool checker);
static void	swap(t_stack_node **stack);
void	sa(t_stack_node **a, bool checker);
void	sb(t_stack_node **b, bool checker);
void	sa(t_stack_node **a, t_stack_node **b, bool checker);

//algo
void	sort_three(t_stack_node **a);
void	sort_five(t_stack_node **a, t_stack_node **b);
static t_stack_node	*get_highest(t_stack_node **stack);
bool	stack_sorted(t_stack_node *stack);

#endif

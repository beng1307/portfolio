#include "push_swap.h"

static void	split_stack(t_list **stack_a, t_list **stack_b, int stack_size)
{
	t_list	*node;
	int	lowest_value;
	int	middle_value;
	int	highest_value;

	lowest_value = get_lowest_value(*stack_a, stack_size);
	middle_value = get_middle_value(*stack_a, stack_size);
	highest_value = get_highest_value(*stack_a, stack_size);
	while (stack_size--)
	{
		node = *stack_a;
		if (node->content != lowest_value
			&& node->content != middle_value
			&& node->content != highest_value)
			ft_pb(stack_a,stack_b);
		else
			ft_ra(stack_a);
	}	
}

static void sort_3(t_list **stack_a)
{
	if ((*stack_a)->content > (*stack_a)->next->content)
		ft_sa(stack_a);
	if ((*stack_a)->next->next->content < (*stack_a)->content)
		ft_rra(stack_a);
	else if ((*stack_a)->next->next->content < (*stack_a)->next->content)
	{
		ft_rra(stack_a);
		ft_sa(stack_a);
	}
}

static int which_half(t_list **stack_a, int value_b, int stack_size)
{
	t_list	*node;
	int		half;

	node = *stack_a;
	half = 0;
	while (!(value_b > node->content && value_b < node->next->content))
		half++;
	if (half < stack_size / 2)
		return (1);
	else
		return (2);
}

void	sort_it(t_list **stack_a, t_list **stack_b)
{
	int	stack_size;

	stack_size = ft_lstsize(*stack_a);
	split_stack(stack_a, stack_b, stack_size);
	sort_3(stack_a);
}

/*
edge case: if first is higher than b_content and last is lower, it 
does not find the right position
*/
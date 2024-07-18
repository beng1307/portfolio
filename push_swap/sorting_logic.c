#include "push_swap.h"

void	split_stack(t_list **stack_a, t_list **stack_b, int stack_size)
{
	t_list	*node;
	int		lowest_value;
	int		middle_value;
	int		highest_value;

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

void sort_3(t_list **stack_a)
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

void	sort_both_stacks(t_list **stack_a, t_list **stack_b, int fastest_value)
{
	t_list	*lastlst_a;

	lastlst_a = ft_lstlast(*stack_a);
	while ((*stack_b)->content != fastest_value 
		&& !((*stack_a)->content > fastest_value
		&& lastlst_a->content < fastest_value))
	{
		if (which_half(stack_a, fastest_value, ft_lstsize(*stack_a), 'a') == 1
			&& which_half(stack_b, fastest_value, ft_lstsize(*stack_b), 'b') == 1)
			ft_rr(stack_a, stack_b);
		else if (which_half(stack_a, fastest_value, ft_lstsize(*stack_a), 'a') == 2
			&& which_half(stack_b, fastest_value, ft_lstsize(*stack_b), 'b') == 2)
			ft_rrr(stack_a, stack_b);
		else
			break ;
		lastlst_a = ft_lstlast(*stack_a);
	}
}

void	sort_one_stack(t_list **stack_a, t_list **stack_b, int fastest_value)
{
	t_list	*lastlst_a;

	lastlst_a = ft_lstlast(*stack_a);
	while ((*stack_b)->content != fastest_value)
	{
		if (which_half(stack_b, fastest_value, ft_lstsize(*stack_b), 'b') == 1)
			ft_rb(stack_b);
		else if (which_half(stack_b, fastest_value, ft_lstsize(*stack_b), 'b') == 2)
			ft_rrb(stack_b);
	}
	while (!((*stack_a)->content > fastest_value
		&& lastlst_a->content < fastest_value))
	{
		if (which_half(stack_a, fastest_value, ft_lstsize(*stack_a), 'a') == 1)
			ft_ra(stack_a);
		else if (which_half(stack_a, fastest_value, ft_lstsize(*stack_a), 'a') == 2)
			ft_rra(stack_a);
		lastlst_a = ft_lstlast(*stack_a);
	}
}

void	sort_into_a(t_list **stack_a, t_list **stack_b, int fastest_value)
{
	sort_both_stacks(stack_a, stack_b, fastest_value);
	sort_one_stack(stack_a, stack_b, fastest_value);
	ft_pa(stack_a, stack_b);
}

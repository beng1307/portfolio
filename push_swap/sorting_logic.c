#include "push_swap.h"

void	split_stack(t_list **stk_a, t_list **stk_b, int stack_size)
{
	t_list	*node;
	int		lowest_value;
	int		middle_value;
	int		highest_value;

	lowest_value = get_lowest_value(*stk_a, stack_size);
	middle_value = get_middle_value(*stk_a, stack_size);
	highest_value = get_highest_value(*stk_a, stack_size);
	while (stack_size--)
	{
		node = *stk_a;
		if (node->content != lowest_value
			&& node->content != middle_value
			&& node->content != highest_value)
			ft_pb(stk_a,stk_b);
		else
			ft_ra(stk_a, stk_b);
	}	
}

void sort_3(t_list **stk_a, t_list **stk_b)
{
	if ((*stk_a)->content > (*stk_a)->next->content)
		ft_sa(stk_a);
	if ((*stk_a)->next->next->content < (*stk_a)->content)
		ft_rra(stk_a, stk_b);
	else if ((*stk_a)->next->next->content < (*stk_a)->next->content)
	{
		ft_rra(stk_a, stk_b);
		ft_sa(stk_a);
	}
}

void	sort_both_stacks(t_list **stk_a, t_list **stk_b, int fastest_value)
{
	t_list	*lastlst_a;

	lastlst_a = ft_lstlast(*stk_a);
	while ((*stk_b)->content != fastest_value 
		&& !((*stk_a)->content > fastest_value
		&& lastlst_a->content < fastest_value))
	{
		if (which_half(stk_a, fastest_value, ft_lstsize(*stk_a), 'a') == 1
			&& which_half(stk_b, fastest_value, ft_lstsize(*stk_b), 'b') == 1)
			ft_rr(stk_a, stk_b);
		else if (which_half(stk_a, fastest_value, ft_lstsize(*stk_a), 'a') == 2
			&& which_half(stk_b, fastest_value, ft_lstsize(*stk_b), 'b') == 2)
			ft_rrr(stk_a, stk_b);
		else
			break ;
		lastlst_a = ft_lstlast(*stk_a);
	}
}

void	sort_one_stack(t_list **stk_a, t_list **stk_b, int fastest_value)
{
	t_list	*lastlst_a;

	lastlst_a = ft_lstlast(*stk_a);
	while ((*stk_b)->content != fastest_value)
	{
		if (which_half(stk_b, fastest_value, ft_lstsize(*stk_b), 'b') == 1)
			ft_rb(stk_a, stk_b);
		else if (which_half(stk_b, fastest_value, ft_lstsize(*stk_b), 'b') == 2)
			ft_rrb(stk_a, stk_b);
	}
	while (!((*stk_a)->content > fastest_value
		&& lastlst_a->content < fastest_value))
	{
		if (which_half(stk_a, fastest_value, ft_lstsize(*stk_a), 'a') == 1)
			ft_ra(stk_a, stk_b);
		else if (which_half(stk_a, fastest_value, ft_lstsize(*stk_a), 'a') == 2)
			ft_rra(stk_a, stk_b);
		lastlst_a = ft_lstlast(*stk_a);
	}
}

void	sort_into_a(t_list **stk_a, t_list **stk_b, int fastest_value)
{
	sort_both_stacks(stk_a, stk_b, fastest_value);
	sort_one_stack(stk_a, stk_b, fastest_value);
	ft_pa(stk_a, stk_b);
}

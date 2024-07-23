#include "../push_swap.h"

void	sort_2(t_list **stk_a, t_list **stk_b, char ab)
{
	if (ab == 'a')
	{
		if ((*stk_a)->content > (*stk_a)->next->content)
			ft_sa(stk_a);
	}
	else if (ab == 'b')
	{
		if ((*stk_b)->content < (*stk_b)->next->content)
			ft_sb(stk_b);
	}
}

void	sort_3(t_list **stk_a, t_list **stk_b)
{
	while (!is_sorted(*stk_a))
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
}

void	sort_4(t_list **stk_a, t_list **stk_b, int lst_size)
{
	int	lowest_value;
	int	highest_value;

	lowest_value = get_lowest_value(*stk_a, lst_size);
	highest_value = get_highest_value(*stk_a, lst_size);
	while (!is_sorted(*stk_a))
	{
		if ((*stk_a)->content > (*stk_a)->next->content
			&& !((*stk_a)->content == highest_value
				&& (*stk_a)->next->content == lowest_value))
			ft_sa(stk_a);
		else
			ft_ra(stk_a, stk_b);
	}
}

void	sort_5(t_list **stk_a, t_list **stk_b)
{
	int	loops;
	int	min_value;

	loops = 2;
	min_value = get_lowest_value(*stk_a, ft_lstsize(*stk_a));
	ft_pb(stk_a, stk_b);
	ft_pb(stk_a, stk_b);
	sort_3(stk_a, stk_b);
	while (loops--)
	{
		if (is_highest(*stk_a, *stk_b) == 1)
			highest_to_a(stk_a, stk_b);
		else
			five_back_together(stk_a, stk_b);
	}
	while (!is_sorted(*stk_a))
	{
		if (which_half(stk_a, min_value, ft_lstsize(*stk_a), 'b') == 1)
			ft_ra(stk_a, stk_b);
		else if (which_half(stk_a, min_value, ft_lstsize(*stk_a), 'b') == 2)
			ft_rra(stk_a, stk_b);
	}
}

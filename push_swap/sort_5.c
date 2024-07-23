#include "push_swap.h"

static void	five_back_together(t_list **stk_a, t_list **stk_b)
{
	while (1)
	{
		ft_rra(stk_b, stk_a);
		if ((*stk_b)->content > (*stk_a)->content)

	}
}

void	sort_5(t_list **stk_a, t_list **stk_b)
{
	int	loops;
	int	lowest_value;

	loops = 2;
	lowest_value = get_lowest_value(*stk_a, ft_lstsize(*stk_a));
	ft_pb(stk_a, stk_b);
	ft_pb(stk_a, stk_b);
	sort_3(stk_a, stk_b);
	while (loops--)
	{
		five_back_together(stk_a, stk_b);
		while ((*stk_a)->content != lowest_value)
			ft_ra(stk_a, stk_b);
	}
}

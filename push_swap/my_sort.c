#include "push_swap.h"

// void	small_sort(t_list **stk_a, t_list **stk_b)
// {
// 	t_list	*last_lst;

// 	if (ft_lstsize(*stk_a) <= 3)
// 		sort_3(stk_a, stk_b);
// 	else
// 	{
// 		while (!is_sorted(*stk_a))
// 		{
// 			last_lst = ft_lastlst(*stk_a);

// 		}
			
// 	}
// }

void	sort_it(t_list **stk_a, t_list **stk_b)
{
	int	stack_size;
	int	lowest_value;

	stack_size = ft_lstsize(*stk_a);
	split_stack(stk_a, stk_b, stack_size);
	sort_3(stk_a, stk_b);
	if (is_sorted(*stk_a) && !*stk_b)
		return ;
	lowest_value = (*stk_a)->content;
	while (!is_sorted(*stk_a) || *stk_b)
	{
		if (*stk_b)
			sort_into_a(stk_a, stk_b, fastest_sort(stk_a, stk_b));
		else
		{
			if (which_half(stk_a, lowest_value, ft_lstsize(*stk_a), 'a') == 1)
				while ((*stk_a)->content != lowest_value)
					ft_ra(stk_a, stk_b);
			else
				while ((*stk_a)->content != lowest_value)
					ft_ra(stk_a, stk_b);
		}
	}
}

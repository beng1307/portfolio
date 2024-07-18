#include "push_swap.h"

void	sort_it(t_list **stack_a, t_list **stack_b)
{
	int	stack_size;
	int	lowest_value;

	stack_size = ft_lstsize(*stack_a);
	split_stack(stack_a, stack_b, stack_size);
	sort_3(stack_a);
	if (is_sorted(*stack_a) && !*stack_b)
		return ;
	lowest_value = (*stack_a)->content;
	while (!is_sorted(*stack_a) || *stack_b)
	{
		if (*stack_b)
			sort_into_a(stack_a, stack_b, fastest_sort(stack_a, stack_b));
		else
			if (which_half(stack_a, lowest_value, ft_lstsize(*stack_a), 'a') == 1)
				while ((*stack_a)->content != lowest_value)
					ft_ra(stack_a);
			else
				while ((*stack_a)->content != lowest_value)
					ft_ra(stack_a);
	}
}

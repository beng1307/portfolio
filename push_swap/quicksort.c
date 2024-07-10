#include "push_swap.h"

static int	get_middle_value(t_list *stack, size_t stack_size)
{
	t_list	*counting_node;
	size_t	return_value;

	counting_node = stack;
	return_value = 0;
	while (counting_node)
	{
		return_value += counting_node->content;
		counting_node = counting_node->next;
	}
	return (return_value / stack_size);
}

void	split_stack(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;
	size_t	stack_size;
	int		middle_value;

	node = *stack_a;
	stack_size = ft_lstsize(*stack_a);
	middle_value = get_middle_value(*stack_a, stack_size);
	while (stack_size-- && node)
	{
		if (node->content <= middle_value)
		{
			node = node->next;
			ft_pb(stack_a, stack_b);
		}
		else
		{
			node = node->next;
			ft_ra(stack_a);
		}
	}
}

void	my_quicksort(t_list **stack_a, t_list **stack_b)
{
	while (is_sorted(*stack_a) == 0 || is_sorted(*stack_b) == 0)
	{
		if (((*stack_a)->content > (*stack_a)->next->content)
			&& ((*stack_b)->content < (*stack_b)->next->content))
			ft_ss(stack_a, stack_b);
		else if ((*stack_a)->content > (*stack_a)->next->content)
			ft_sa(stack_a);
		else if ((*stack_b)->content < (*stack_b)->next->content)
			ft_sb(stack_b);
		else
			ft_rr(stack_a, stack_b);
	}
	while (stack_b)
		ft_pa(stack_a, stack_b);
}

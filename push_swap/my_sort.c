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
+	return (return_value / stack_size);
}

static void	split_stack(t_list **stack_a, t_list **stack_b)
{
	t_list	*node;
	int		middle_value;
	int		stack_size;
	static int count = 0;

	node = *stack_a;
	stack_size = ft_lstsize(*stack_a);
	middle_value = get_middle_value(*stack_a, stack_size);
	while (stack_size > 0)
	{
		if (node->content <= middle_value)
		{
			ft_pb(stack_a, stack_b);
			ft_putnbr_fd(count++, 1);
			ft_putchar_fd('\n', 1);
		}
		else if (node->content > middle_value)
		{
			ft_ra(stack_a);
			ft_putnbr_fd(count++, 1);
			ft_putchar_fd('\n', 1);
		}
		node = *stack_a;
		stack_size--;
	}
}

void	sort_it(t_list **stack_a, t_list **stack_b, int stack_size)
{
	if (stack_size <= 1)
		return ;
	split_stack(stack_b, stack_a);
	sort_it(stack_a, stack_b, ft_lstsize(*stack_a));
	sort_it(stack_b, stack_a, ft_lstsize(*stack_b));
	while (*stack_b)
		ft_pa(stack_a, stack_b);
}

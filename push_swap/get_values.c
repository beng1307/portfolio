#include "push_swap.h"

static int  ft_abs(int a, int b)
{
    if (a - b < 0)
        return ((a - b) * -1);
    else
        return (a - b);
}

int	get_lowest_value(t_list *stk_a, int stack_size)
{
	t_list	*node;
	int		lowest_value;

	node = stk_a;
	lowest_value = node->content;
	while (stack_size--)
	{
		if (node->content < lowest_value)
			lowest_value = node->content;
		node = node->next;
	}
	return (lowest_value);
}

int	get_highest_value(t_list *stk_a, int stack_size)
{
	t_list	*node;
	int		highest_value;

	node = stk_a;
	highest_value = node->content;
	while (stack_size--)
	{
		if (node->content > highest_value)
			highest_value = node->content;
		node = node->next;
	}
	return (highest_value);
}

int	get_middle_value(t_list *stk_a, int stack_size)
{
	t_list	*node;
	int		mid;
	int		lowest_value;
	int		highest_value;
	int		middle_value;

	node = stk_a;
	lowest_value = get_lowest_value(stk_a, stack_size);
	highest_value = get_highest_value(stk_a, stack_size);
	mid = ((long)highest_value + lowest_value) / 2;
	middle_value = node->content;
	while (stack_size--)
	{
		if (ft_abs(node->content, mid) < ft_abs(middle_value, mid))
			middle_value = node->content;
		node = node->next;
	}
	return (middle_value);
}

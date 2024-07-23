#include "../push_swap.h"

int	which_half(t_list **stack, int value_b, int stack_size, char ab)
{
	t_list	*node;
	int		half;

	node = *stack;
	half = 0;
	while (node && (!(value_b > node->content && value_b < node->next->content)
			&& value_b != node->content) && ab == 'a')
	{
		half++;
		node = node->next;
	}
	while (node && value_b != node->content && ab == 'b')
	{
		half++;
		node = node->next;
	}
	if (half < stack_size / 2)
		return (1);
	else
		return (2);
}

static int	count_moves_b(t_list **stk_b, int content_b)
{
	t_list	*node_b;
	int		moves_b;

	node_b = *stk_b;
	moves_b = 1;
	while (node_b->content != content_b)
	{
		moves_b++;
		node_b = node_b->next;
	}
	if (which_half(stk_b, node_b->content, ft_lstsize(*stk_b), 'b') == 2)
	{
		moves_b = 1;
		while (node_b)
		{
			moves_b++;
			node_b = node_b->next;
		}
	}
	return (moves_b);
}

static int	count_moves_a(t_list **stk_a, int content_b)
{
	t_list	*node_a;
	t_list	*last_node;
	int		moves_a;

	node_a = *stk_a;
	last_node = ft_lstlast(*stk_a);
	moves_a = 1;
	if (content_b < node_a->content && content_b > last_node->content)
		return (0);
	while (!(content_b > node_a->content && content_b < node_a->next->content))
	{
		moves_a++;
		node_a = node_a->next;
	}
	if (which_half(stk_a, content_b, ft_lstsize(*stk_a), 'a') == 2)
	{
		moves_a = 0;
		while (node_a)
		{
			moves_a++;
			node_a = node_a->next;
		}
	}
	return (moves_a);
}

int	fastest_sort(t_list **stk_a, t_list **stk_b)
{
	t_list	*node_b;
	int		moves_a;
	int		moves_b;
	int		min_moves;
	int		value_to_sort;

	node_b = *stk_b;
	min_moves = ft_lstsize(*stk_a) + ft_lstsize(*stk_b);
	while (node_b)
	{
		moves_a = count_moves_a(stk_a, node_b->content);
		moves_b = count_moves_b(stk_b, node_b->content);
		if (moves_a + moves_b < min_moves)
		{
			value_to_sort = node_b->content;
			min_moves = moves_a + moves_b;
		}
		node_b = node_b->next;
	}
	return (value_to_sort);
}

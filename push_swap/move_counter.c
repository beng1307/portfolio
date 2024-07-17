#include "push_swap.h"

static int	count_moves_b(t_list **stack_b, int content_b)
{
	t_list	*node_b;
	int		moves_b;

	node_b = *stack_b;
	moves_b = 1;
	while (node_b->content != content_b)
	{
		moves_b++;
		node_b = node_b->next;
	}
	if (which_half(stack_b, node_b->content) == 2)
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

static int	count_moves_a(t_list **stack_a, int content_b)
{
	t_list	*node_a;
	t_list	*last_node;
	int		moves_a;

	node_a = *stack_a;
	last_node = ft_lstlast(*stack_a);
	moves_a = 0;
	if (content_b < node_a->content && content_b > last_node->content)
		return (0);
	while (!(content_b > node_a->content && content_b < node_a->next->content))
	{
		moves_a++;
		node_a = node_a->next;
	}
	if (which_half(stack_a, node_a->content) == 2)
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

int	fastest_sort(t_list **stack_a, t_list **stack_b)
{
	t_list	*node_b;
	int		moves_a;
	int		moves_b;
	int		min_moves;
	int		value_to_sort;

	node_b = *stack_b;
	min_moves = ft_lstsize(stack_a) + ft_lstsize(stack_b);
	while (node_b)
	{
		moves_a = count_moves_a(stack_a, node_b->content);
		moves_b = count_moves_a(stack_a, node_b->content);
		if (moves_a + moves_b < min_moves)
		{
			value_to_sort = node_b->content;
			min_moves = moves_a + moves_b;
		}
		node_b = node_b->next;
	}
	return (value_to_sort);
}
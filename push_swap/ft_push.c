#include "push_swap.h"

void    ft_pa(t_list **stack_a, t_list **stack_b)
{
	t_list *head;

    if (stack_a && stack_b)
	{
		head = *stack_b;
		*stack_b = (*stack_b)->next;
		if (*stack_a)		
    		ft_lstadd_front(stack_a, head);
		else
		{
			*stack_a = ft_lstnew((head)->content);
			ft_lstdelone(head);
		}
		head = NULL;
		ft_putendl_fd("pa", 1);
	}
}

void    ft_pb(t_list **stack_a, t_list **stack_b)
{
	t_list	*head;

    if (stack_a && stack_b)
	{
		head = *stack_a;		
		*stack_a = (*stack_a)->next;
		if (*stack_b)
        	ft_lstadd_front(stack_b, head);
		else
		{
			*stack_b = ft_lstnew((head)->content);
			ft_lstdelone(head);
		}
		head = NULL;
		ft_putendl_fd("pb", 1);
	}
}
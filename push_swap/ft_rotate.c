#include "push_swap.h"

void    ft_ra(t_list **stack_a)
{
    t_list  *head;

    if (stack_a && *stack_a && (*stack_a)->next)
	{
        head = *stack_a;
        ft_lstadd_back(stack_a, ft_lstnew((*stack_a)->content));
        stack_a = &(*stack_a)->next;
        ft_lstdelone(head);
        head = NULL;
        ft_putendl_fd("ra", 1);
	}
}

void    ft_rb(t_list **stack_b)
{
    t_list  *head;

    if (stack_b && *stack_b && (*stack_b)->next)
	{
        head = *stack_b;
        ft_lstadd_back(stack_b, ft_lstnew((*stack_b)->content));
        stack_b = &(*stack_b)->next;
        ft_lstdelone(head);
        head = NULL;
        ft_putendl_fd("rb", 1);
	}
}

void    ft_rr(t_list **stack_a, t_list **stack_b)
{
    t_list  *head;

    if ((stack_a && stack_b)
        && (*stack_a && (*stack_a)->next)
            && (*stack_b && (*stack_b)->next))
    {
        head = *stack_a;
        ft_lstadd_back(stack_a, ft_lstnew((*stack_a)->content));
        stack_a = &(*stack_a)->next;
        ft_lstdelone(head);
        head = *stack_b;
        ft_lstadd_back(stack_b, ft_lstnew((*stack_b)->content));
        stack_b = &(*stack_b)->next;
        ft_lstdelone(head);
        head = NULL;
		ft_putendl_fd("rr", 1);
    }
}
#include "push_swap.h"

void    ft_rra(t_list **stack_a)
{
    t_list  *lastlst;
    t_list  *head;

    if (stack_a && *stack_a && (*stack_a)->next)
	{
        lastlst = ft_lstlast(*stack_a);
        head = *stack_a;
        ft_lstadd_front(stack_a, ft_lstnew(lastlst->content));
        while (head->next && head->next->next)
            head = head->next;
        ft_lstdelone(lastlst);
        lastlst = NULL;
        head->next = NULL;
        head = NULL;
		ft_putendl_fd("rra", 1);
	}
}

void    ft_rrb(t_list **stack_b)
{
    t_list	*lastlst;
    t_list	*head;

    if (stack_b && *stack_b && (*stack_b)->next)
	{
		lastlst = ft_lstlast(*stack_b);
		head = *stack_b;
		ft_lstadd_front(stack_b, ft_lstnew(lastlst->content));
		while (head->next && head->next->next)
			head = head->next;
		ft_lstdelone(lastlst);
		lastlst = NULL;
		head->next = NULL;
		head = NULL;
		ft_putendl_fd("rrb", 1);
	}
}

void    ft_rrr(t_list **stack_a, t_list **stack_b)
{
    t_list  *lastlst;
	t_list	*head;

    if ((stack_a && stack_b)
        && (*stack_a && (*stack_a)->next)
            && (*stack_b && (*stack_b)->next))
    {
        lastlst = ft_lstlast(*stack_a);
        head = *stack_a;
        ft_lstadd_front(stack_a, ft_lstnew(lastlst->content));
        while (head->next && head->next->next)
            head = head->next;
        ft_lstdelone(lastlst);
		head->next = NULL;
		lastlst = ft_lstlast(*stack_b);
		head = *stack_b;
		ft_lstadd_front(stack_b, ft_lstnew(lastlst->content));
		while (head->next && head->next->next)
			head = head->next;
		ft_lstdelone(lastlst);
		lastlst = NULL;
		head->next = NULL;
		head = NULL;
	    ft_putendl_fd("rrr", 1);
    }
}

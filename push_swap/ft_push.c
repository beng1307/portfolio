#include "push_swap.h"

void    ft_pa(t_list **stk_a, t_list **stk_b)
{
	t_list	*head;
	int		content;

    if (stk_a && (stk_b && *stk_b))
	{
		head = *stk_b;
		content = (*stk_b)->content;
		*stk_b = (*stk_b)->next;
		ft_lstdelone(head);
		head = NULL;
		if (*stk_a)
    		ft_lstadd_front(stk_a, head);
		else
			*stk_a = ps_lstnew(content, stk_a, stk_b);
		ft_putendl_fd("pa", 1);
	}
}

void    ft_pb(t_list **stk_a, t_list **stk_b)
{
	t_list	*head;
	int		content;

    if ((stk_a && *stk_a) && stk_b)
	{
		head = *stk_a;
		content = (*stk_a)->content;
		*stk_a = (*stk_a)->next;
		ft_lstdelone(head);
		head = NULL;
		if (*stk_b)
			ft_lstadd_front(stk_b, head);
		else
			*stk_b = ps_lstnew(content, stk_a, stk_b);
		ft_putendl_fd("pb", 1);
	}
}
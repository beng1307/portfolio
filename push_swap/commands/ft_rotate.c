#include "../push_swap.h"

void	ft_ra(t_list **stk_a, t_list **stk_b)
{
	t_list	*head;

	if (stk_a && *stk_a && (*stk_a)->next)
	{
		head = *stk_a;
		ft_lstadd_back(stk_a, ps_lstnew((*stk_a)->content, stk_a, stk_b));
		*stk_a = (*stk_a)->next;
		ft_lstdelone(head);
		head = NULL;
		ft_putendl_fd("ra", 1);
	}
}

void	ft_rb(t_list **stk_a, t_list **stk_b)
{
	t_list	*head;

	if (stk_b && *stk_b && (*stk_b)->next)
	{
		head = *stk_b;
		ft_lstadd_back(stk_b, ps_lstnew((*stk_b)->content, stk_a, stk_b));
		*stk_b = (*stk_b)->next;
		ft_lstdelone(head);
		head = NULL;
		ft_putendl_fd("rb", 1);
	}
}

void	ft_rr(t_list **stk_a, t_list **stk_b)
{
	t_list	*head;

	if ((stk_a && stk_b)
		&& (*stk_a && (*stk_a)->next)
		&& (*stk_b && (*stk_b)->next))
	{
		head = *stk_a;
		ft_lstadd_back(stk_a, ps_lstnew((*stk_a)->content, stk_a, stk_b));
		*stk_a = (*stk_a)->next;
		ft_lstdelone(head);
		head = *stk_b;
		ft_lstadd_back(stk_b, ps_lstnew((*stk_b)->content, stk_a, stk_b));
		stk_b = (*stk_b)->next;
		ft_lstdelone(head);
		head = NULL;
		ft_putendl_fd("rr", 1);
	}
}

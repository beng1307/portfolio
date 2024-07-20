#include "push_swap.h"

void    ft_rra(t_list **stk_a, t_list **stk_b)
{
    t_list  *lastlst;
    t_list  *head;

    if (stk_a && *stk_a && (*stk_a)->next)
	{
        lastlst = ft_lstlast(*stk_a);
        head = *stk_a;
        ft_lstadd_front(stk_a, ps_lstnew(lastlst->content, stk_a, stk_b));
        while (head->next && head->next->next)
            head = head->next;
        ft_lstdelone(lastlst);
        lastlst = NULL;
        head->next = NULL;
        head = NULL;
		ft_putendl_fd("rra", 1);
	}
}

void    ft_rrb(t_list **stk_a, t_list **stk_b)
{
    t_list	*lastlst;
    t_list	*head;

    if (stk_b && *stk_b && (*stk_b)->next)
	{
		lastlst = ft_lstlast(*stk_b);
		head = *stk_b;
		ft_lstadd_front(stk_b, ps_lstnew(lastlst->content, stk_a, stk_b));
		while (head->next && head->next->next)
			head = head->next;
		ft_lstdelone(lastlst);
		lastlst = NULL;
		head->next = NULL;
		head = NULL;
		ft_putendl_fd("rrb", 1);
	}
}

void    ft_rrr(t_list **stk_a, t_list **stk_b)
{
    t_list  *lastlst;
	t_list	*head;

    if ((stk_a && stk_b)
        && (*stk_a && (*stk_a)->next)
            && (*stk_b && (*stk_b)->next))
    {
        lastlst = ft_lstlast(*stk_a);
        head = *stk_a;
        ft_lstadd_front(stk_a, ps_lstnew(lastlst->content, stk_a, stk_b));
        while (head->next && head->next->next)
            head = head->next;
        ft_lstdelone(lastlst);
		head->next = NULL;
		lastlst = ft_lstlast(*stk_b);
		head = *stk_b;
		ft_lstadd_front(stk_b, ps_lstnew(lastlst->content, stk_a, stk_b));
		while (head->next && head->next->next)
			head = head->next;
		ft_lstdelone(lastlst);
		lastlst = NULL;
		head->next = NULL;
		head = NULL;
	    ft_putendl_fd("rrr", 1);
    }
}

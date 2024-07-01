#include "push_swap.h"

void    ft_rra(t_list *stack_a)
{
    if (stack_a)
	{
        ft_lstadd_front(&stack_a, ft_lstlast(stack_a));
		ft_putendl_fd("rra", 1);
	}
}

void    ft_rrb(t_list *stack_b)
{
    if (stack_b)
	{
        ft_lstadd_front(&stack_b, ft_lstlast(stack_b));
		ft_putendl_fd("rrb", 1);
	}
}

void    ft_rrr(t_list *stack_a, t_list *stack_b)
{
    if (stack_a && stack_b)
    {
        ft_lstadd_front(&stack_a, ft_lstlast(stack_a));
        ft_lstadd_front(&stack_b, ft_lstlast(stack_b));
	    ft_putendl_fd("rrr", 1);
    }
}
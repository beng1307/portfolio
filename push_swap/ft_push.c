#include "push_swap.h"

void    ft_pa(t_list *stack_a, t_list *stack_b)
{
    if (stack_b)
	{
        ft_lstadd_front(&stack_a, stack_b);
		ft_putendl_fd("pa", 1);
	}
}

void    ft_pb(t_list *stack_a, t_list *stack_b)
{
    if (stack_a)
	{
        ft_lstadd_front(&stack_b, stack_a);
		ft_putendl_fd("pb", 1);
	}
}
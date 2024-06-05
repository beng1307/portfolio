#include "push_swap.h"

void    ft_ra(t_list *stack_a)
{
    if (stack_a)
        ft_lstadd_back(&stack_a, stack_a);
}

void    ft_rb(t_list *stack_b)
{
    if (stack_b)
        ft_lstadd_back(&stack_b, stack_b);
}

void    ft_rr(t_list *stack_a, t_list *stack_b)
{
    if (stack_a && stack_b)
    {
        ft_lstadd_back(&stack_a, stack_a);
        ft_lstadd_back(&stack_b, stack_b);
    }
}
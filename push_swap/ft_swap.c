#include "push_swap.h"

void    ft_sa(t_list *stack_a)
{
    if (stack_a && stack_a->next)
        ft_lstadd_front(&stack_a, stack_a->next);
}

void    ft_sb(t_list *stack_b)
{
    if (stack_b && stack_b->next)
        ft_lstadd_front(&stack_b, stack_b->next);
}

void    ft_ss(t_list *stack_a, t_list *stack_b)
{
    if ((stack_a && stack_a->next) && (stack_b && stack_b->next))
    {
        ft_lstadd_front(&stack_a, stack_a->next);
        ft_lstadd_front(&stack_b, stack_b->next);
    }
}
#include "push_swap.h"

void    ft_sa(t_list **stack_a)
{
    int temp;

    if (stack_a && *stack_a && (*stack_a)->next)
	{
        temp = (*stack_a)->content;
        (*stack_a)->content = (*stack_a)->next->content;
        (*stack_a)->next->content = temp;
		ft_putendl_fd("sa", 1);
	}
}

void    ft_sb(t_list **stack_b)
{
    int temp;

    if (stack_b && *stack_b && (*stack_b)->next)
	{
        temp = (*stack_b)->content;
        (*stack_b)->content = (*stack_b)->next->content;
        (*stack_b)->next->content = temp;
		ft_putendl_fd("sb", 1);
	}
}

void    ft_ss(t_list **stack_a, t_list **stack_b)
{
    int temp;
 
    if ((stack_a && stack_b)
        && (*stack_a && (*stack_a)->next)
            && (*stack_b && (*stack_b)->next))
    {
        temp = (*stack_a)->content;
        (*stack_a)->content = (*stack_a)->next->content;
        (*stack_a)->next->content = temp;
        temp = (*stack_b)->content;
        (*stack_b)->content = (*stack_b)->next->content;
        (*stack_b)->next->content = temp;        
		ft_putendl_fd("ss", 1);
    }
}
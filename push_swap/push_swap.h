#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

void	split_stack(t_list **stack_a, t_list **stack_b);

void	split_stack_a(t_list **stack_a);

void	split_stack_b(t_list **stack_b);

void	my_quicksort(t_list **stack_a, t_list **stack_b);

int		is_sorted(t_list *stack_a);

void    ft_pa(t_list **stack_a, t_list **stack_b);

void    ft_pb(t_list **stack_a, t_list **stack_b);

void    ft_sa(t_list **stack_a);

void    ft_sb(t_list **stack_b);

void    ft_ss(t_list **stack_a, t_list **stack_b);

void    ft_ra(t_list **stack_a);

void    ft_rb(t_list **stack_b);

void    ft_rr(t_list **stack_a, t_list **stack_b);

void    ft_rra(t_list **stack_a);

void    ft_rrb(t_list **stack_b);

void    ft_rrr(t_list **stack_a, t_list **stack_b);

#endif
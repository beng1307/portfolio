#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

int		get_lowest_value(t_list *stack_a, int stack_size);

int		get_highest_value(t_list *stack_a, int stack_size);

int		get_middle_value(t_list *stack_a, int stack_size);

int		fastest_sort(t_list **stack_a, t_list **stack_b);

void	sort_it(t_list **stack_a, t_list **stack_b);

int		is_sorted_b(t_list *stack);

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
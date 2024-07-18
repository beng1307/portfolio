#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

void	check_args(int ac, const char **av);

t_list	*split_into_list(const char *arg);

t_list	*get_list(int argc, const char **arg);

int		get_lowest_value(t_list *stack_a, int stack_size);

int		get_highest_value(t_list *stack_a, int stack_size);

int		get_middle_value(t_list *stack_a, int stack_size);

int		fastest_sort(t_list **stack_a, t_list **stack_b);

int 	which_half(t_list **stack, int value_b, int stack_sizen, char ab);

void	split_stack(t_list **stack_a, t_list **stack_b, int stack_size);

void 	sort_3(t_list **stack_a);

void	sort_into_a(t_list **stack_a, t_list **stack_b, int fastest_value);

void	sort_it(t_list **stack_a, t_list **stack_b);

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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:16:28 by bgretic           #+#    #+#             */
/*   Updated: 2024/07/24 12:16:34 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

void	five_back_together(t_list **stk_a, t_list **stk_b);

void	highest_to_a(t_list **stk_a, t_list **stk_b);

int		mini_which_half(t_list **stack, int value_b, int stack_size);

int		which_one(t_list *stk_a, t_list *stk_b);

int		is_highest(t_list *stk_a, t_list *stk_b);

void	small_sort(t_list **stk_a, t_list **stk_b);

void	sort_2(t_list **stk_a, t_list **stk_b, char ab);

void	sort_3(t_list **stk_a, t_list **stk_b);

void	sort_4(t_list **stk_a, t_list **stk_b, int lst_size);

void	sort_5(t_list **stk_a, t_list **stk_b);

void	free_that(char **to_free);

t_list	*newlst(int content, t_list **list, char **spl_arg);

t_list	*ps_create_new(int content, t_list **list);

t_list	*ps_lstnew(int content, t_list **stk_a, t_list **stk_b);

void	check_form(const char **av);

int		check_nums(char **args);

t_list	*split_into_list(char *arg);

t_list	*get_list(int argc, char **arg);

int		get_lowest_value(t_list *stk_a, int stack_size);

int		get_highest_value(t_list *stk_a, int stack_size);

int		get_middle_value(t_list *stk_a, int stack_size);

int		fastest_sort(t_list **stk_a, t_list **stk_b);

int		which_half(t_list **stack, int value_b, int stack_sizen, char ab);

void	split_stack(t_list **stk_a, t_list **stk_b, int stack_size);

void	sort_into_a(t_list **stk_a, t_list **stk_b, int fastest_value);

void	sort_it(t_list **stk_a, t_list **stk_b);

int		is_sorted(t_list *stk_a);

void	ft_pa(t_list **stk_a, t_list **stk_b);

void	ft_pb(t_list **stk_a, t_list **stk_b);

void	ft_sa(t_list **stk_a);

void	ft_sb(t_list **stk_b);

void	ft_ss(t_list **stk_a, t_list **stk_b);

void	ft_ra(t_list **stk_a, t_list **stk_b);

void	ft_rb(t_list **stk_a, t_list **stk_b);

void	ft_rr(t_list **stk_a, t_list **stk_b);

void	ft_rra(t_list **stk_a, t_list **stk_b);

void	ft_rrb(t_list **stk_a, t_list **stk_b);

void	ft_rrr(t_list **stk_a, t_list **stk_b);

#endif

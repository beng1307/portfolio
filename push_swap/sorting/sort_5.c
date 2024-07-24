/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:20:14 by bgretic           #+#    #+#             */
/*   Updated: 2024/07/24 12:20:15 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_highest(t_list *stk_a, t_list *stk_b)
{
	t_list	*node;

	node = stk_a;
	while (node)
	{
		if (stk_b->content < node->content)
			return (0);
		node = node->next;
	}
	return (1);
}

int	which_one(t_list *stk_a, t_list *stk_b)
{
	t_list	*node;
	int		next_number;

	node = stk_a;
	while (node)
	{
		if (stk_b->content < node->content)
		{
			next_number = node->content;
			break ;
		}
		node = node->next;
	}
	while (node)
	{
		if (node->content > stk_b->content && node->content < next_number)
			next_number = node->content;
		node = node->next;
	}
	return (next_number);
}

int	mini_which_half(t_list **stack, int value_b, int stack_size)
{
	t_list	*node;
	int		half;

	node = *stack;
	half = 0;
	while (node && value_b != node->content)
	{
		half++;
		node = node->next;
	}
	if (half <= stack_size / 2)
		return (1);
	else
		return (2);
}

void	highest_to_a(t_list **stk_a, t_list **stk_b)
{
	t_list	*lastlst;
	int		highest_num;

	lastlst = ft_lstlast(*stk_a);
	highest_num = get_highest_value(*stk_a, ft_lstsize(*stk_a));
	while (lastlst->content != highest_num)
	{
		if (mini_which_half(stk_a, highest_num, ft_lstsize(*stk_a)) == 1)
			ft_ra(stk_a, stk_b);
		else if (mini_which_half(stk_a, highest_num, ft_lstsize(*stk_a)) == 2)
			ft_rra(stk_a, stk_b);
		lastlst = ft_lstlast(*stk_a);
	}
	ft_pa(stk_a, stk_b);
}

void	five_back_together(t_list **stk_a, t_list **stk_b)
{
	int	next_number;

	next_number = which_one(*stk_a, *stk_b);
	while ((*stk_a)->content != next_number)
	{
		if (mini_which_half(stk_a, next_number, ft_lstsize(*stk_a)) == 1)
			ft_ra(stk_a, stk_b);
		else if (mini_which_half(stk_a, next_number, ft_lstsize(*stk_a)) == 2)
			ft_rra(stk_a, stk_b);
	}
	ft_pa(stk_a, stk_b);
}

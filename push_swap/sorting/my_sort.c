/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:20:00 by bgretic           #+#    #+#             */
/*   Updated: 2024/07/24 12:20:02 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	small_sort(t_list **stk_a, t_list **stk_b)
{
	int	lst_size;

	lst_size = ft_lstsize(*stk_a);
	if (lst_size == 2)
		sort_2(stk_a, stk_b, 'a');
	else if (lst_size == 3)
		sort_3(stk_a, stk_b);
	else if (lst_size == 4)
		sort_4(stk_a, stk_b, lst_size);
	else if (lst_size == 5)
		sort_5(stk_a, stk_b);
}

void	sort_it(t_list **stk_a, t_list **stk_b)
{
	int	stack_size;
	int	lowest_value;

	stack_size = ft_lstsize(*stk_a);
	split_stack(stk_a, stk_b, stack_size);
	sort_3(stk_a, stk_b);
	if (is_sorted(*stk_a) && !*stk_b)
		return ;
	lowest_value = (*stk_a)->content;
	while (!is_sorted(*stk_a) || *stk_b)
	{
		if (*stk_b)
			sort_into_a(stk_a, stk_b, fastest_sort(stk_a, stk_b));
		else
		{
			if (which_half(stk_a, lowest_value, ft_lstsize(*stk_a), 'a') == 1)
				while ((*stk_a)->content != lowest_value)
					ft_ra(stk_a, stk_b);
			else
				while ((*stk_a)->content != lowest_value)
					ft_rra(stk_a, stk_b);
		}
	}
}

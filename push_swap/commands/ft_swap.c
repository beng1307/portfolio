/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:19:03 by bgretic           #+#    #+#             */
/*   Updated: 2024/07/24 12:19:04 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_sa(t_list **stk_a)
{
	int	temp;

	if (stk_a && *stk_a && (*stk_a)->next)
	{
		temp = (*stk_a)->content;
		(*stk_a)->content = (*stk_a)->next->content;
		(*stk_a)->next->content = temp;
		ft_putendl_fd("sa", 1);
	}
}

void	ft_sb(t_list **stk_b)
{
	int	temp;

	if (stk_b && *stk_b && (*stk_b)->next)
	{
		temp = (*stk_b)->content;
		(*stk_b)->content = (*stk_b)->next->content;
		(*stk_b)->next->content = temp;
		ft_putendl_fd("sb", 1);
	}
}

void	ft_ss(t_list **stk_a, t_list **stk_b)
{
	int	temp;

	if ((stk_a && stk_b)
		&& (*stk_a && (*stk_a)->next)
		&& (*stk_b && (*stk_b)->next))
	{
		temp = (*stk_a)->content;
		(*stk_a)->content = (*stk_a)->next->content;
		(*stk_a)->next->content = temp;
		temp = (*stk_b)->content;
		(*stk_b)->content = (*stk_b)->next->content;
		(*stk_b)->next->content = temp;
		ft_putendl_fd("ss", 1);
	}
}

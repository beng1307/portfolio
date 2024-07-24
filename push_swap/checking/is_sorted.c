/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorted.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:17:54 by bgretic           #+#    #+#             */
/*   Updated: 2024/07/24 12:17:55 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_list *stack)
{
	t_list	*test;

	test = stack;
	while (test && test->next)
	{
		if ((test)->content > (test)->next->content)
			return (0);
		test = test->next;
	}
	return (1);
}

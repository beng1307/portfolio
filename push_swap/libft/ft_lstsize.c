/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:17:33 by bgretic           #+#    #+#             */
/*   Updated: 2024/07/24 12:17:34 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*counter;
	int		count;

	counter = lst;
	count = 0;
	while (counter != NULL)
	{
		count++;
		counter = counter->next;
	}
	return (count);
}

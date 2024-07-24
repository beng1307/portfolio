/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:17:05 by bgretic           #+#    #+#             */
/*   Updated: 2024/07/24 12:17:06 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*to_clear;

	if (lst)
	{
		to_clear = *lst;
		while (to_clear)
		{
			to_clear = to_clear->next;
			free(*lst);
			*lst = to_clear;
		}
		*lst = NULL;
	}
}

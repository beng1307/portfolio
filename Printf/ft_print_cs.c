/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_c.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:49:51 by bgretic           #+#    #+#             */
/*   Updated: 2024/05/02 18:12:02 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_print_c(int c)
{
	size_t	count;

	count = 0;
	return (count += write(1, &c,1));
}

size_t	ft_print_s(char *str)
{
	size_t count;

	count = 0;
	while (str[count] != '\0')
		count += write(1, &str[count], 1);
	return (count);
}


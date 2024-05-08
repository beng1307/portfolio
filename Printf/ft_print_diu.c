/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_diu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:01:35 by bgretic           #+#    #+#             */
/*   Updated: 2024/05/08 12:01:38 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//Prints numbers.
size_t	ft_print_d(int n)
{
	char	*str;
	size_t	len;

	str = ft_itoa(n);
	len = ft_strlen(str);
	write(1, &*str, len);
	free(str);
	return (len);
}

//Prints unsigned numbers.
size_t	ft_print_u(unsigned int n)
{
	char	*str;
	size_t	len;

	str = ft_utoa(n);
	len = ft_strlen(str);
	write(1, &*str, len);
	free(str);
	return (len);
}

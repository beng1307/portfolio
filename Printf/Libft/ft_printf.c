/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 12:29:55 by bgretic           #+#    #+#             */
/*   Updated: 2024/05/02 18:42:05 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_c(int c, size_t to_return);

//Handles the edgecase when there is a single % sign without spezifier.
/*size_t	error_handle_single_pers(const char *str)
{
	const char  *formats;

	formats = "cspdiuxX%";
	while (*str)
	{
		if (*str == '%' && ft_strchr(formats, (int)str + 1) == 0)
			return (1);
		str++;
	}
	return (0);
}*/

//Prints the needed format.
void	print_it(const char *str, size_t to_return, va_list list)
{
	if (*str + 1 == 'c')
		print_c(va_arg(list, int), to_return);
/*	else if (*str + 1 == '%')
		print_c(va_arg(list, int));
	else if (*str + 1 == 's')
		print_s(va_arg(list, char*));
	else if (*str + 1 == 'd')
		print_(va_arg(list, int));
	else if (*str + 1 == 'i')
		print_(va_arg(list, int));
	else if (*str + 1 == 'u')
		print_(va_arg(list, unsigned int));
	else if (*str + 1 == 'x')
		print_(va_arg(list, ));
	else if (*str + 1 == 'X')
		print_(va_arg(list, ));
	else if (*str + 1 == 'p')
		print_(va_arg(list, void*));*/
}

//Does what printf does.
int	ft_printf(const char *str, ...)
{
	va_list list;
	size_t	to_return;

	to_return = 0;
	va_start(list, str);
	/*if (error_handle_single_pers(str) == 1)
		return (-1);*/
	while (*str)
	{
		if (*str == '%')
			print_it(str++, to_return, list);
		else
			ft_putchar_fd(*str, 1);
		str++;
	}
	va_end(list);
	return (to_return);
}

//test

int	main(void)
{
	char	test = 'b';
	ft_printf("Hello World! %c 42!\n", test);
}

//Notes
//
//I have to check for edgecases.
//I have to handle printf format and look up the Video from Oceano again.
//How can i put the right type inside of va_arg.

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
#include <stdio.h>

void	print_c(int c, size_t to_return);
void	print_s(char *arg, size_t to_return);
void	print_d(int n, size_t to_return);

//Handles the edgecase when there is a single % sign without spezifier.
size_t	error_handle_single_pers(const char *str)
{
	const char	*formats;
	size_t		multiple_pers_check;

	formats = "cspdiuxX%";
	multiple_pers_check = 0;
	while (*str)
	{
		if (*str == '%')
		{
			if (*str == '%' && ft_strchr(formats, *(str + 1)) == 0)
				return (1);
			multiple_pers_check = 1;
		}
		if (multiple_pers_check == 0)
			str++;
		else
			str += 2;
		multiple_pers_check = 0;
	}
	return (0);
}

//Prints the needed format.
void	print_it(const char *str, size_t to_return, va_list list)
{
	if (*(str + 1) == 'c')
		print_c(va_arg(list, int), to_return);
	else if (*(str + 1) == '%')
		to_return += write(1, "%", 1);
	else if (*(str + 1) == 's')
		print_s(va_arg(list, char*), to_return);
	else if (*(str + 1) == 'd' || *(str + 1) == 'i')
		print_d(va_arg(list, int), to_return);
/*	else if (*(str + 1) == 'u')
		print_(va_arg(list, unsigned int));
	else if (*(str + 1) == 'x')
		print_(va_arg(list, ));
	else if (*(str + 1) == 'X')
		print_(va_arg(list, ));
	else if (*(str + 1) == 'p')
		print_(va_arg(list, void*));*/
}

//Does what printf does.
int	ft_printf(const char *str, ...)
{
	va_list list;
	size_t	to_return;

	to_return = 0;
	va_start(list, str);
	if (error_handle_single_pers(str) == 1)
		return (-1);
	while (*str)
	{
		if (*str == '%')
			print_it(str++, to_return, list);
		else
			ft_putchar_fd(*str, 1);
		str++;
		to_return++;
	}
	va_end(list);
	return (to_return);
}

//test

int	main(void)
{
	int	test_return;
	char	*test = "yoo";

	printf("%d\n", test_return = ft_printf("Hello World! %% %% 42!\n"));
	printf("%d\n", test_return = ft_printf("Hello World! %s 42!\n", test));
	printf("%d\n", test_return = ft_printf("Hello World! %s %d!\n", test, test_di));
	//printf("Hello World! %% 42!\n");
}

//Notes
//
//I have to check for edgecases.
//My print_s returns not the right return value!
//Let's check my %d and %i

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 12:21:48 by bgretic           #+#    #+#             */
/*   Updated: 2024/07/24 12:21:50 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static long int	ft_long_atoi(const char *str)
{
	long int	nbr;
	int			sign;

	nbr = 0;
	sign = 1;
	while (*str && (*str == ' '))
		str++;
	if (*str && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			sign = -sign;
		str++;
	}
	while (*str && (*str >= '0' && *str <= '9'))
	{
		nbr = nbr * 10 + *str - '0';
		str++;
		if (nbr / 2 > INT_MAX)
			return (nbr * (long)sign);
	}
	return (nbr * (long)sign);
}

static void	check_form_cases(const char *arg)
{
	int	is_error;
	int	is_empty;

	is_error = 0;
	is_empty = 1;
	while (*arg)
	{
		if (ft_isdigit(*arg))
			is_empty = 0;
		if (!(ft_isdigit(*arg) || *arg == ' ' || *arg == '-'))
			is_error = 1;
		if (*arg == '-' && !(*(arg + 1) >= '0' && *(arg + 1) <= '9'))
			is_error = 1;
		if (ft_isdigit(*arg) && !(ft_isdigit(*(arg + 1))
				|| *(arg + 1) == ' ' || *(arg + 1) == '\0'))
			is_error = 1;
		arg++;
	}
	if (is_error == 1 || is_empty == 1)
	{
		ft_putendl_fd("Error", 2);
		exit(-1);
	}
}

void	check_form(const char **args)
{
	const char	*arg;
	size_t		index;

	index = 1;
	while (args[index])
	{
		arg = args[index++];
		check_form_cases(arg);
	}
}

static int	is_duplicate(char **args, long int nbr, size_t index)
{
	long int	compare_nbr;
	size_t		index2;

	index2 = 0;
	while (args[index2])
	{
		compare_nbr = ft_long_atoi(args[index2]);
		if (nbr == compare_nbr && index != index2)
			return (1);
		index2++;
	}
	return (0);
}

int	check_nums(char **args)
{
	long int	nbr;
	size_t		index;

	index = 0;
	while (args[index])
	{
		nbr = ft_long_atoi(args[index]);
		if (nbr < INT_MIN || nbr > INT_MAX
			|| is_duplicate(args, nbr, index))
			return (-1);
		index++;
	}
	return (0);
}

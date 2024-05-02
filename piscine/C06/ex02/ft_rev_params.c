/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 20:41:39 by bgretic           #+#    #+#             */
/*   Updated: 2024/01/27 20:56:49 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, &*str, 1);
		str++;
	}
}

int	main(int ac, char **av)
{
	int	i;

	i = ac;
	if (ac > 1)
	{
		while (i > 1)
		{
			ft_putstr(av[i - 1]);
			write(1, "\n", 1);
			i--;
		}
	}
}

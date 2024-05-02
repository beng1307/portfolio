/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 19:46:19 by bgretic           #+#    #+#             */
/*   Updated: 2024/01/27 20:03:07 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *name)
{
	while (*name)
	{
		write(1, &*name, 1);
		name++;
	}
}

int	main(int ac, char **av)
{
	char	*name;

	if (ac == 1)
	{
		name = av[0];
		ft_putstr(name);
		write(1, "\n", 1);
	}
}

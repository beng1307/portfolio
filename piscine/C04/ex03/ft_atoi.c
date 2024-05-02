/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 17:42:34 by bgretic           #+#    #+#             */
/*   Updated: 2024/01/26 12:01:52 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	j;
	int	minusnbr;
	int	nbr;

	j = 0;
	minusnbr = 0;
	nbr = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			minusnbr++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nbr *= 10;
		nbr += *str - 48;
		str++;
	}
	if (minusnbr % 2)
		return (-nbr);
	return (nbr);
}

/*int	main(int ac, char *av[])
{
	ac = 2;
	printf("%d", ft_atoi(av[1]));
}*/

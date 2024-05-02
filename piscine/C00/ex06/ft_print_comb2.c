/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 21:12:27 by bgretic           #+#    #+#             */
/*   Updated: 2024/01/31 10:28:26 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_digits(int num)
{
	if (num < 10)
	{
		ft_putchar('0');
		ft_putchar((num % 10) + '0');
	}
	else
	{
		ft_putchar((num / 10) + '0');
		ft_putchar((num % 10) + '0');
	}
}

void	ft_print_comb2(void)
{
	int	num_1;
	int	num_2;

	num_1 = 0;
	num_2 = 1;
	while (num_1 <= 98 && num_2 <= 99)
	{
		print_digits(num_1);
		ft_putchar(' ');
		print_digits(num_2);
		if (!(num_1 >= 98 && num_2 >= 99))
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
		num_2++;
		if (num_2 > 99)
		{
			num_1++;
			num_2 = num_1 + 1;
		}
	}
}

/*int	main(void)
{
	ft_print_comb2();
}*/

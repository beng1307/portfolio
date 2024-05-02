/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 16:57:44 by bgretic           #+#    #+#             */
/*   Updated: 2024/01/11 19:10:17 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_comb(void)
{
	int	num_1;
	int	num_2;
	int	num_3;

	num_1 = '0';
	while (num_1 <= '7')
	{
		num_2 = num_1 + 1;
		while (num_2 <= '8')
		{
			num_3 = num_2 + 1;
			while (num_3 <= '9')
			{
				write(1, &num_1, 1);
				write(1, &num_2, 1);
				write(1, &num_3, 1);
				if (!(num_1 == '7' && num_2 == '8' && num_3 == '9'))
					write (1, ", ", 2);
				num_3++;
			}
			num_2++;
		}
		num_1++;
	}
}

/*int	main(void)
{
	ft_print_comb();
}*/

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:54:59 by bgretic           #+#    #+#             */
/*   Updated: 2024/01/11 16:40:52 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_reverse_alphabet(void)
{
	char	letter_1;

	letter_1 = 'z';
	while (letter_1 >= 'a')
	{
		write(1, &letter_1, 1);
		letter_1--;
	}
}

/*int	main(void)
{
	ft_print_reverse_alphabet();
}*/

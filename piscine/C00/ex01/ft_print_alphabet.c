/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 12:07:29 by bgretic           #+#    #+#             */
/*   Updated: 2024/01/11 16:41:24 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	char	letter_1;

	letter_1 = 'a';
	while (letter_1 <= 'z')
	{
		write(1, &letter_1, 1);
		letter_1++;
	}
}

/*int	main(void)
{
	ft_print_alphabet();
}*/

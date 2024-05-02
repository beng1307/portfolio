/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_negative.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 15:07:38 by bgretic           #+#    #+#             */
/*   Updated: 2024/01/11 16:42:51 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_is_negative(int n)
{
	char	letter;

	if (n >= 0)
	{
		letter = 'P';
		write(1, &letter, 1);
	}
	else if (n < 0)
	{
		letter = 'N';
		write(1, &letter, 1);
	}
}

/*int	main(void)
{
	ft_is_negative(n);
}*/

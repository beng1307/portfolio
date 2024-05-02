/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:54:23 by bgretic           #+#    #+#             */
/*   Updated: 2024/01/30 18:20:14 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 1;
	while (str[i] != '\0')
	{
		if (str[0] >= 'a' && str[0] <= 'z')
		{
			str[0] -= 32;
		}
		else if (str[i] == ' ')
		{
			if (str[i + 1] >= 'a' && str[i + 1] <= 'z')
			{
				str[i + 1] -= 32;
				i += 2;
			}
		}
		else if ((str[i] >= 'A' && str[i] <= 'Z') && (str[i - 1] != ' '))
		{
			str[i] += 32;
		}
		i++;
	}
	return (str);
}

/*int	main(int ac, char **av)
{
	if (ac > 0)
	{
		printf("%s", ft_strcapitalize(av[1]));
	}
}*/

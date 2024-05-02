/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 15:06:42 by bgretic           #+#    #+#             */
/*   Updated: 2024/01/24 15:58:59 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}
/*int	main(void)
{
	char	test[25] = "Hey";
	char	test2[25] = "Hey";

	ft_strcmp(test, test2);
	printf("%d", ft_strcmp(test, test2));
	if (ft_strcmp(test, test2) == 0)
	{
	}
	else if (ft_strcmp(test, test2) > 0)
	{
	}
	else if (ft_strcmp(test, test2) < 0)
	{
	}
}*/

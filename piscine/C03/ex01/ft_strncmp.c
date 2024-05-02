/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 22:29:59 by bgretic           #+#    #+#             */
/*   Updated: 2024/01/24 21:29:07 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && (s1[i] != '\0' || s2[i] != '\0'))
	{
		if (s1[i] > s2[i])
		{
			return (s1[i] - s2[i]);
		}
		else if (s1[i] < s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}
/*int	main(void)
{
	char	test[25] = "test123";
	char	test2[25] = "test";

	ft_strncmp(test, test2, 20);
	if (ft_strncmp(test, test2, 20) < 0)
    {
		printf("s2 is higher then s1");
    }
	else if (ft_strncmp(test, test2, 20) > 0)
    {
		printf("s1 is higher then s2");
    }
	else
	{
		printf("They are equal");
	}

}*/

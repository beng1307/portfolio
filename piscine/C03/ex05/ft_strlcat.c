/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/21 09:50:35 by bgretic           #+#    #+#             */
/*   Updated: 2024/01/24 16:05:51 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_length;
	unsigned int	src_length;

	i = 0;
	dest_length = ft_strlen(dest);
	src_length = ft_strlen(src);
	if (dest_length >= size)
	{
		return (size + src_length);
	}
	while (src[i] != '\0' && i < (size - dest_length) - 1)
	{
		dest[dest_length + i] = src[i];
		i++;
	}
	dest[dest_length + i] = '\0';
	return (dest_length + src_length);
}

/*int	main(void)
{
	char	test[25] = "Hello";
	char	test2[25] = "Friene";

	printf("%d\t", ft_strlcat(test,test2,3));
	printf("%s", test);
}*/

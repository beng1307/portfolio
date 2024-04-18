/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 12:29:54 by bgretic           #+#    #+#             */
/*   Updated: 2024/04/18 13:47:12 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>

static int	ft_split_lenghtcount(const char *s, char c, int array)
{
	int	count;
	int	skip_to_arr;

	count = 0;
	skip_to_arr = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		while (*s && *s != c)
		{
			if (skip_to_arr == array)
				count++;
			s++;
		}
		skip_to_arr++;
	}
	return (count);
}

static int	ft_split_wordcount(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static int	ft_freemem(char **str, int array)
{
	int	i;

	i = 0;
	while (i < array)
	{
		free(str[i]);
		i++;
	}
	return (0);
}

static char	**ft_splitcpy(char **str, const char *s, char c)
{
	int		i;
	int		array;

	i = 0;
	array = 0;
	while (*s)
	{
		str[array] = malloc(ft_split_lenghtcount(s, c, array + 1));
		if (str[array] == NULL)
			ft_freemem(str, array);
		while (*s && *s == c)
			s++;
		while (*s && *s != c)
		{
			str[array][i] = *s;
			s++;
			i++;
		}
		array++;
		i = 0;
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char	**str;

	str = malloc(ft_split_wordcount(s, c) * sizeof(char *));
	if (str == NULL)
		return (NULL);
	ft_splitcpy(str, s, c);
	return (str);
}

//test
/*
#include <stdio.h>

int	main(void)
{
	char	*test = "Hello,Frienne,and,Hello,Friod!";
	char	seperator = ',';
	char	**test2 = ft_split(test, seperator);

	printf("%s\n", test2[0]);
	printf("%s\n", test2[1]);
	printf("%s\n", test2[2]);
	printf("%s\n", test2[3]);
	printf("%s\n", test2[4]);
}
*/

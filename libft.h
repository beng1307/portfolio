/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/09 18:37:32 by bgretic           #+#    #+#             */
/*   Updated: 2024/04/09 19:27:09 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int				ft_atoi(const char *nptr);

void			ft_bzero(void *s, size_t n);

void			*ft_calloc(size_t nmemb, size_t size);

int				ft_isalnum(int argument);

int				ft_isalpha(int argument);

int				ft_isascii(int c);

int				ft_isdigit(int arg);

int				ft_isprint(int c);

void			*ft_memchr(const void *s, int c, size_t n);

int				ft_memcmp(const void *s1, const void *s2, size_t n);

void			*ft_memcpy(void *dest, const void *src, size_t n);

void			*ft_memmove(void *dest, const void *src, size_t n);

void			*ft_memset(void *s, int c, size_t n);

char			*ft_strchr(char *str, int c);

char			*ft_strdup(const char *s);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

size_t			ft_strlcpy(char *dest, const char *src, size_t size);

int				ft_strlen(char *str);

int				ft_strncmp(const char *str1, const char *str2, size_t num);

char			*ft_strnstr(const char *big, const char *little, size_t len);

char			*ft_strrchr(char *str, int c);

int				ft_tolower(int ch);

int				ft_toupper(int ch);

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:51:39 by bgretic           #+#    #+#             */
/*   Updated: 2024/05/21 17:35:22 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char    *get_next_line(int fd);
size_t  ft_strlen(const char *str);
char    *ft_strchr(const char *str, int c);
char	*ft_strdup(const char *s);
char	*ft_strjoin(char *s1, char *s2);

#endif
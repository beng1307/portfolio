/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 14:51:39 by bgretic           #+#    #+#             */
/*   Updated: 2024/05/16 19:14:53 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stdlib.h>
#include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

typedef struct s_list
{
    char            *content;
    struct s_list   *next;
}                   t_list;

char    *get_next_line(int fd);
t_list  *ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
char    *ft_strchr(const char *str, int c);
size_t  ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);

#endif
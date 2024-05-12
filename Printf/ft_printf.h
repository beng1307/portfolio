/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:02:22 by bgretic           #+#    #+#             */
/*   Updated: 2024/05/08 12:29:07 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"

int		ft_printf(const char *str, ...);

char	*ft_utoa(unsigned int n);

size_t	ft_print_c(int c);

size_t	ft_print_s(char *arg);

size_t	ft_print_d(int n);

size_t	ft_print_u(unsigned int n);

size_t	ft_print_x(size_t x);

size_t	ft_print_upper_x(size_t X);

size_t	ft_print_p(void *p);

#endif

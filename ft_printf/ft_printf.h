/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgretic <bgretic@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 12:02:22 by bgretic           #+#    #+#             */
/*   Updated: 2024/05/17 20:14:31 by bgretic          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "./libft/libft.h"

int		ft_printf(const char *str, ...);

size_t	ft_print_c(int c);

size_t	ft_print_s(char *arg);

size_t	ft_print_d(int n);

size_t	ft_print_u(unsigned int n);

size_t	ft_print_x(unsigned int x);

size_t	ft_print_upper_x(unsigned int X);

size_t	ft_print_p(void *p);

#endif

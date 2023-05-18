/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patatoss <patatoss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 23:10:05 by patatoss          #+#    #+#             */
/*   Updated: 2023/05/13 16:08:00 by patatoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

int		ft_printf(const char *str, ...);
int		check_case(const char *str, int *i, va_list al);
int		ft_printf_putchar(char c);
int		ft_printf_putstr(char *str);
int		ft_printf_putptr(int *address);
int		ft_printf_ultoabase(unsigned long n, char *base);
int		ft_ltoa_base(long n, char *base);

char	*ft_str_rev(char *str);

#endif

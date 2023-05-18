/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patatoss <patatoss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/10 23:13:55 by patatoss          #+#    #+#             */
/*   Updated: 2023/05/13 16:06:43 by patatoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_case(const char *str, int *i, va_list al)
{
	size_t	count;

	(*i)++;
	if (str[*i] == '%')
		count = ft_printf_putchar('%');
	else if (str[*i] == 'c')
		count = ft_printf_putchar(va_arg(al, int));
	else if (str[*i] == 's')
		count = ft_printf_putstr(va_arg(al, char *));
	else if (str[*i] == 'p')
		count = ft_printf_putptr(va_arg(al, void *));
	else if (str[*i] == 'd' || str[*i] == 'i')
		count = ft_ltoa_base(va_arg(al, int), "0123456789");
	else if (str[*i] == 'u')
		count = ft_printf_ultoabase(va_arg(al, unsigned int), "0123456789");
	else if (str[*i] == 'x')
		count = ft_ltoa_base(va_arg(al, int), "0123456789abcdef");
	else if (str[*i] == 'X')
		count = ft_ltoa_base(va_arg(al, int), "0123456789ABCDEF");
	return (count);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	size_t	count;
	va_list	al;

	i = 0;
	count = 0;
	va_start(al, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			count += check_case(str, &i, al);
			i++;
		}
		ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(al);
	return (count);
}

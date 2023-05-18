/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patatoss <patatoss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 11:41:33 by patatoss          #+#    #+#             */
/*   Updated: 2023/05/13 15:44:57 by patatoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_ultoabase(unsigned long n, char *base)
{
	char	*str;
	size_t	i;
	size_t	base_len;

	str = malloc(sizeof(char) * 32 + 1);
	if (!str)
		return (0);
	i = 0;
	base_len = ft_strlen(base);
	while (n)
	{
		str[i] = base[n % base_len];
		n /= base_len;
		i++;
	}
	str[i] = '\0';
	str = ft_str_rev(str);
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putptr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patatoss <patatoss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 00:43:25 by patatoss          #+#    #+#             */
/*   Updated: 2023/05/13 15:46:55 by patatoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_str_rev(char *str)
{
	char	*new_str;
	int		i;
	int		j;

	i = 0;
	j = ft_strlen(str);
	new_str = malloc(sizeof(char) * j + 1);
	if (!new_str)
		return (NULL);
	new_str[j--] = '\0';
	while (j >= 0)
		new_str[j--] = str[i++];
	return (new_str);
}

char	*ft_printf_ltoa_base(long n, char *base)
{
	char	*str;
	size_t	i;
	size_t	base_len;

	str = malloc(sizeof(char) * 32 + 1);
	if (!str)
		return (NULL);
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
	return (str);
}

char	*ft_add_0x_prefix(char *str)
{
	char	*new_str;
	int		i;

	new_str = malloc(sizeof(char) * (ft_strlen(str) + 2) + 1);
	if (!new_str)
		return (NULL);
	i = 0;
	new_str[0] = '0';
	new_str[1] = 'x';
	while (str[i])
	{
		new_str[i + 2] = str[i];
		i++;
	}
	new_str[i + 2] = '\0';
	return (new_str);
}

int	ft_printf_putptr(int *address)
{
	long	cast_address;
	char	*new_address;

	if (!address)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	cast_address = (long)address;
	new_address = ft_printf_ltoa_base(cast_address, "0123456789abcdef");
	if (!new_address)
		return (0);
	new_address = ft_add_0x_prefix(new_address);
	ft_putstr_fd(new_address, 1);
	return (ft_strlen(new_address));
}

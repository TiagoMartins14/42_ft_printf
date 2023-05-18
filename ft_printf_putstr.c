/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putstr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: patatoss <patatoss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 00:11:16 by patatoss          #+#    #+#             */
/*   Updated: 2023/05/12 09:01:33 by patatoss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_putstr(char *str)
{	
	if (!str)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	ft_putstr_fd(str, 1);
	return (strlen(str));
}

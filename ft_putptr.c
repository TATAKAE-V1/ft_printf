/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofarhat <ofarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 22:48:51 by ofarhat           #+#    #+#             */
/*   Updated: 2022/11/14 00:20:36 by ofarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putptr_hex(size_t n, int *len)
{
	char	*base;

	base = "0123456789abcdef";
	if (n < 16)
		ft_putchar(base[n % 16], len);
	else
	{
		ft_putptr_hex(n / 16, len);
		ft_putptr_hex(n % 16, len);
	}
}

void	ft_putptr(void *p, int *len)
{
	size_t	n;

	n = (size_t)p;
	ft_putstr("0x", len);
	ft_putptr_hex(n, len);
}

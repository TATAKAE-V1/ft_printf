/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ofarhat <ofarhat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 00:00:46 by ofarhat           #+#    #+#             */
/*   Updated: 2022/11/14 22:26:58 by ofarhat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check(va_list p, const char c, int *len)
{
	if (c == 'c')
		ft_putchar(va_arg(p, int), len);
	else if (c == 's')
		ft_putstr(va_arg(p, char *), len);
	else if (c == 'p')
		ft_putptr(va_arg(p, void *), len);
	else if (c == 'd' || c == 'i')
		ft_putnbr(va_arg(p, int), len);
	else if (c == 'u')
		ft_putunsigned(va_arg(p, unsigned int), len);
	else if (c == 'x' || c == 'X')
		ft_puthexa(va_arg(p, int), c, len);
	else if (c == '%')
		ft_putchar(c, len);
}

int	ft_printf(const char *str, ...)
{
	int		len;
	int		i;
	va_list	p;

	len = 0;
	i = 0;
	va_start(p, str);
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1])
		{
			i++;
			ft_check(p, str[i], &len);
		}
		else if (str[i] != '%')
			ft_putchar(str[i], &len);
		i++;
	}
	va_end(p);
	return (len);
}

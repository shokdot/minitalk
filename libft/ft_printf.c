/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:26:34 by healeksa          #+#    #+#             */
/*   Updated: 2024/04/04 18:15:22 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_printf.h"

int	ft_format(char c, va_list arg)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar_fd(va_arg(arg, int), 1);
	else if (c == 's')
		len += ft_putstr(va_arg(arg, char *), 1);
	else if (c == 'p')
		len += ft_print_ptr(va_arg(arg, unsigned long long));
	else if (c == 'd' || c == 'i')
		len += ft_putnbr(va_arg(arg, int));
	else if (c == 'u')
		len += ft_uputnbr(va_arg(arg, unsigned int));
	else if (c == 'x' || c == 'X')
		len += ft_print_hex(va_arg(arg, unsigned int), c);
	else if (c == '%')
		len += ft_putchar_fd('%', 1);
	return (len);
}

int	ft_printf(const char *s, ...)
{
	int		i;
	int		n;
	va_list	arg;

	i = 0;
	n = 0;
	va_start(arg, s);
	while (s[i])
	{
		if (s[i] == '%')
		{
			n += ft_format(s[i + 1], arg);
			i++;
		}
		else
			n += ft_putchar_fd(s[i], 1);
		i++;
	}
	va_end(arg);
	return (n);
}

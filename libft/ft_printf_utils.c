/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 16:31:04 by healeksa          #+#    #+#             */
/*   Updated: 2024/04/04 17:44:15 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_printf.h"

int	ft_count_digits(unsigned int n)
{
	int	count;

	count = 0;
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

int	ft_uputnbr(unsigned long n)
{
	int		digit_count;
	char	*num;
	int		count;

	if (n == 0)
		return (write(1, "0", 1));
	digit_count = ft_count_digits(n);
	num = (char *)malloc(sizeof(char) * (digit_count + 1));
	if (!num)
		return (0);
	num[digit_count] = '\0';
	while (n != 0)
	{
		digit_count--;
		num[digit_count] = n % 10 + '0';
		n /= 10;
	}
	count = ft_strlen(num);
	ft_putstr(num, 1);
	free(num);
	return (count);
}

int	ft_print_hex(unsigned long long n, char format)
{
	char	*hex;
	int		res;

	res = 0;
	if (n >= 16)
	{
		res += ft_print_hex(n / 16, format);
		res += ft_print_hex(n % 16, format);
	}
	else
	{
		if (n == 0)
			res = ft_putchar_fd('0', 1);
		hex = "0123456789abcdef";
		while (n != 0)
		{
			if (format == 'X')
				res += ft_putchar_fd(ft_toupper(hex[n % 16]), 1);
			else
				res += ft_putchar_fd(hex[n % 16], 1);
			n /= 16;
		}
	}
	return (res);
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	res;

	res = 0;
	res += ft_putstr("0x", 1);
	res += ft_print_hex(ptr, 'x');
	return (res);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 12:31:18 by healeksa          #+#    #+#             */
/*   Updated: 2024/04/04 17:48:52 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/libft.h"

int	ft_putnbr(int n)
{
	char	*num;
	int		count;

	num = ft_itoa(n);
	count = ft_strlen(num);
	ft_putstr(num, 1);
	free(num);
	return (count);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:14:11 by healeksa          #+#    #+#             */
/*   Updated: 2024/04/06 21:02:14 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/headers/ft_printf.h"
#include <signal.h>
#include <stdio.h>

void	send_signal(int pid, char *str)
{
	int	str_i;
	int	len;
	int	i;

	len = ft_strlen(str);
	str_i = 0;
	while (str[str_i] != '\0')
	{
		i = 8;
		while (i--)
		{
			if ((str[str_i] >> i) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i--;
			usleep(1000);
		}
		str_i++;
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("Invalid process ID or sending message");
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	if (!pid)
		ft_printf("Invalid process ID");
	send_signal(pid, argv[2]);
}

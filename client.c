/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 12:14:11 by healeksa          #+#    #+#             */
/*   Updated: 2024/04/07 20:35:19 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/headers/ft_printf.h"
#include <signal.h>
#include <stdio.h>

void	send_signal(int pid, char *str)
{
	int	i;
	int	j;

	j = 0;
	while (str[j] != '\0')
	{
		i = 8;
		while (i--)
		{
			if ((str[j] >> i) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(1000);
		}
		j++;
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR2);
		usleep(1000);
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
	{
		ft_printf("Invalid process ID");
		exit(1);
	}
	send_signal(pid, argv[2]);
	return (0);
}

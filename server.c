/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:02:14 by healeksa          #+#    #+#             */
/*   Updated: 2024/04/07 20:35:28 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/headers/libft.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void	process(int signal)
{
	static int				count = 0;
	static unsigned char	c = 0;

	c <<= 1;
	count++;
	if (signal == SIGUSR1)
		c |= 1;
	if (count >= 8)
	{
		if (c == 0)
			ft_printf("\n");
		else
			ft_printf("%c", (char)c);
		c = 0;
		count = 0;
	}
}

int	main(void)
{
	ft_printf("The process id of server is %d\n", (int)getpid());
	signal(SIGUSR1, process);
	signal(SIGUSR2, process);
	while (1)
	{
		pause();
	}
}

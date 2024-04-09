/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/08 19:52:48 by healeksa          #+#    #+#             */
/*   Updated: 2024/04/09 22:35:38 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/headers/libft.h"
#include <signal.h>

void	process(int signal, siginfo_t *info, void *context)
{
	static int				count = 0;
	static unsigned char	c = 0;

	(void)context;
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
		kill(info->si_pid, SIGUSR1);
		c = 0;
		count = 0;
	}
}

int	main(void)
{
	struct sigaction	sig;

	ft_printf("\n \
███╗   ███╗██╗███╗   ██╗██╗████████╗ █████╗ ██╗     ██╗  ██╗ \n \
████╗ ████║██║████╗  ██║██║╚══██╔══╝██╔══██╗██║     ██║ ██╔╝ \n \
██╔████╔██║██║██╔██╗ ██║██║   ██║   ███████║██║     █████╔╝ \n \
██║╚██╔╝██║██║██║╚██╗██║██║   ██║   ██╔══██║██║     ██╔═██╗ \n \
██║ ╚═╝ ██║██║██║ ╚████║██║   ██║   ██║  ██║███████╗██║  ██╗ \n \
╚═╝     ╚═╝╚═╝╚═╝  ╚═══╝╚═╝   ╚═╝   ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝ \
                                                            \n");
	ft_printf("The process id of the server is %d\n", (int)getpid());
	sig.sa_sigaction = process;
	sigemptyset(&sig.sa_mask);
	sig.sa_flags = SA_RESTART;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	while (1)
	{
		pause();
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: healeksa <healeksa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 18:02:14 by healeksa          #+#    #+#             */
/*   Updated: 2024/04/06 21:03:09 by healeksa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/headers/libft.h"
#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int	main(void)
{
	printf("The process id of server is %d\n", (int)getpid());
	// signal(SIGUSR1, process);
	// signal(SIGUSR2, process);
	// printf("\033[0;32m");
	while (1)
		;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:13:07 by maneddam          #+#    #+#             */
/*   Updated: 2023/02/09 17:05:46 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	manipulate(int signo, siginfo_t *info, void *context)
{
	(void)context;
	(void)info;
	static int	i;
	static int	j;

	j++;
	if (signo == SIGUSR1)
		i = (i | 1);
	if (j == 8)
	{
		ft_putchar(i);
		i = 0;
		j = 0;
	}
	else
		i = i << 1;
	usleep(200);
}


int	main(int argc, char *argv[])
{
	int	pid;
	struct sigaction sa;

	(void)argv;
	if (argc == 1)
	{
		pid = getpid();
		sa.sa_sigaction = &manipulate;
		sa.sa_flags = SA_SIGINFO;
		sigemptyset(&sa.sa_mask);

		ft_printf(GREEN" ⚙️->\tprocess id : %d ⚙️\n", pid);
		ft_printf(PURPLE"Waiting for a message from the client 🕙"RESET);
		while (1)
			pause();
	}
}

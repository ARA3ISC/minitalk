/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:13:07 by maneddam          #+#    #+#             */
/*   Updated: 2023/02/18 23:18:49 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	print_error(char *msg)
{
	ft_printf(RED "🚫 %s 🚫\n", msg);
	exit(EXIT_FAILURE);
}

void	manipulate(int signo, siginfo_t *info, void *context)
{
	static int	i;
	static int	j;

	(void)context;
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
	kill(info->si_pid, SIGUSR1);
}

int	main(int argc, char *argv[])
{
	int					pid;
	struct sigaction	sa;

	(void)argv;
	if (argc == 1)
	{
		pid = getpid();
		ft_printf(GREEN " ⚙️->\tprocess id : %d ⚙️\n", pid);
		ft_printf(PURPLE "Waiting for a message from the client 🕙" RESET);
		sa.sa_sigaction = manipulate;
		sa.sa_flags = SA_SIGINFO;
		sigemptyset(&sa.sa_mask);
		if (sigaction(SIGUSR1, &sa, NULL) == -1)
			print_error("No process is running under this PID!!");
		if (sigaction(SIGUSR2, &sa, NULL) == -1)
			print_error("No process is running under this PID!!");
		while (1)
			pause();
	}
}

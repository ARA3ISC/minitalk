/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:12:59 by maneddam          #+#    #+#             */
/*   Updated: 2023/02/09 16:59:25 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

int		target_pid;

void	print_error(char *msg)
{
	ft_printf(RED"🚫 %s 🚫\n", msg);
	exit(EXIT_FAILURE);
}

void	send_data(pid_t target_pid, int c)
{
	int	bit;
	int	err;

	bit = 7;
	while (bit >= 0)
	{
		if ((c & (1 << bit)) != 0)
			err = kill(target_pid, SIGUSR1);
		else
			err = kill(target_pid, SIGUSR2);
		if (err < 0)
			print_error("No process is running under this PID!!");
		usleep(200);
		bit--;
	}
}

void	check(int signo, siginfo_t *info, void	*context)
{
	(void)context;
	if (signo == SIGUSR1 && target_pid == info->si_pid)
		ft_printf("\e[033;0;32m→	Sent signal to server. ✅\e[0m\n");
	else
	{
		ft_printf("\e[033;0;31m→	Wrong signal. ❌\e[0m\n");
		exit(1);
	}
}

int	main(int argc, char *argv[])
{
	char	*msg;
	int		i;
	struct sigaction sa;

	if (argc == 3)
	{
		target_pid = ft_atoi(argv[1]);
		if (target_pid < 0)
			print_error("No process is running under this PID!!");
		msg = argv[2];
		i = 0;

		sa.sa_sigaction = check;
		sa.sa_flags = SA_SIGINFO;
		sigemptyset(&sa.sa_mask);
		if (sigaction(SIGUSR1, &sa, NULL) == -1)
		{
			ft_printf("\e[033;0;31m→	Ops!! PID not correct. ❌\e[0m\n");
			exit(1);
		}
		while (msg[i])
		{
			send_data(target_pid, msg[i]);
			i++;
		}
		send_data(target_pid, '\n');
	}
}

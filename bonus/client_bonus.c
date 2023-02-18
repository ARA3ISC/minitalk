/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 15:12:59 by maneddam          #+#    #+#             */
/*   Updated: 2023/02/18 23:18:54 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	print_error(char *msg)
{
	ft_printf(RED "🚫 %s 🚫\n", msg);
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

void	check(int signo)
{
	if (signo == SIGUSR1)
		ft_printf(GREEN "→	Message sent successfuly. ✅\n");
}

int	main(int argc, char *argv[])
{
	int		target_pid;
	char	*msg;
	int		i;

	if (argc == 3)
	{
		target_pid = ft_atoi(argv[1]);
		if (target_pid < 0)
			print_error("No process is running under this PID!!");
		msg = argv[2];
		i = 0;
		signal(SIGUSR1, &check);
		while (msg[i])
		{
			send_data(target_pid, msg[i]);
			i++;
		}
		send_data(target_pid, '\n');
	}
}

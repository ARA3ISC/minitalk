/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:17:08 by maneddam          #+#    #+#             */
/*   Updated: 2023/02/09 21:50:25 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

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
		while (msg[i])
		{
			send_data(target_pid, msg[i]);
			i++;
		}
		send_data(target_pid, '\n');
	}
}
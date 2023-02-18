/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maneddam <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 19:01:23 by maneddam          #+#    #+#             */
/*   Updated: 2023/02/18 23:19:04 by maneddam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk.h"

void	manipulate(int signo)
{
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
}

int	main(int argc, char *argv[])
{
	int	pid;

	(void)argv;
	if (argc == 1)
	{
		pid = getpid();
		ft_printf(GREEN " ⚙️->\tprocess id : %d ⚙️\n", pid);
		ft_printf(PURPLE "Waiting for a message from the client 🕙" RESET);
		while (1)
		{
			signal(SIGUSR2, &manipulate);
			signal(SIGUSR1, &manipulate);
			pause();
		}
	}
}

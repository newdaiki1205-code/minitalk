/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:15:28 by dshirais          #+#    #+#             */
/*   Updated: 2026/01/12 19:31:15 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int g_switch;

int	bit_op(unsigned char uc, int count)
{
	unsigned char	a;

	if (count == 8)
		return (-1);
	a = uc & (128 >> count);
	a = a >> (7 - count);
	if(a == 1)
		return SIGUSR1;
	else
		return SIGUSR2;
}

void	send_signal(char *str, pid_t pid)
{
	int	i;
	int	j;
	int sig;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (j < 8)
		{
			g_switch = 0;
			sig = bit_op(str[i], j);
			if(kill(pid, sig) == -1)
			{
				ft_printf("Signal Error\n");
				exit(1);
			}
			while (g_switch == 0)
				pause();
			j++;
		}
		i++;
	}
}

void	finish_signal(pid_t pid)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		g_switch = 0;
		kill(pid, SIGUSR2);
		while(g_switch == 0)
			pause();
		i++;
	}
}

void	handler(int signum)
{
	if (signum == SIGUSR2)
	{
		ft_printf("I got your message!");
		exit(0);
	}
	g_switch = 1;
}

int	main(int ac, char **av)
{
	pid_t				pid;
	struct sigaction	sa;

	if (ac != 3)
		return (1);
	sa.sa_handler = handler;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	pid = ft_atoi(av[1]);
	if (pid < 1)
	{
		ft_printf("Error: PID should be a positive integer\n");
		return (1);
	}
	send_signal(av[2], pid);
	finish_signal(pid);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 14:55:27 by dshirais          #+#    #+#             */
/*   Updated: 2026/01/12 19:37:36 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

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
			sig = bit_op(str[i], j);
			if(kill(pid, sig) == -1)
			{
				ft_printf("Signal Error\n");
				exit(1);
			}
			j++;
			usleep(100);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	pid_t	pid;

	if (ac != 3)
		return (1);
	pid = ft_atoi(av[1]);
	if (pid < 1)
	{
		ft_printf("Error: PID should be a positive integer\n");
		return (1);
	}
	send_signal(av[2], pid);
	return (0);
}

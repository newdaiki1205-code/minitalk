/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:15:44 by dshirais          #+#    #+#             */
/*   Updated: 2026/01/13 18:40:41 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	g_buf[10700000000];

void	print_and_clear(char *buf, int pos)
{
	buf[pos] = '\n';
	buf[pos + 1] = '\0';
	ft_printf("%s", buf);
	ft_bzero(buf, pos);
}

void	act(int signum, siginfo_t *info, void *context)
{
	static char	a;
	static int	count;
	static int	pos;

	(void)context;
	a = a << 1;
	if (signum == SIGUSR1)
		a = a + 1;
	count++;
	if (count > 7)
	{
		if (a == '\0')
		{
			print_and_clear(g_buf, pos);
			pos = 0;
			kill(info->si_pid, SIGUSR2);
		}
		else
		{
			g_buf[pos] = a;
			pos++;
		}
		count = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = act;
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_SIGINFO;
	ft_printf("PID: %i\n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
}

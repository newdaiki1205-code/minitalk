/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 16:15:44 by dshirais          #+#    #+#             */
/*   Updated: 2026/01/12 19:08:24 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	act(int signum, siginfo_t *info, void *context)
{
	static char	a;
	static int	count;

	(void)context;
	a = a << 1;
	if (signum == SIGUSR1)
		a = a + 1;
	count++;
	if (count > 7)
	{
		if (a == '\0')
		{
			kill(info->si_pid, SIGUSR2);
			ft_printf("\n");
		}
		else
			ft_printf("%c", a);
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

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 15:40:30 by dshirais          #+#    #+#             */
/*   Updated: 2026/01/08 17:23:57 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int i;
 
static void handler(int signum)
{

    static char a;

    if(i == 0)
        a = 0;    
    a = a << 1;
    if(signum == SIGUSR1)
        a = a + 1;
    i++;
    if(i > 7)
    {
        ft_printf("%c", a);
        i = 0;
    }
}

int main(void)
{
    struct sigaction sa;

    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;

    ft_printf("PID: %i\n", getpid());
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    i = 0;
    while(1)
    {
        pause();
    }
}
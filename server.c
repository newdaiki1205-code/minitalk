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
#include <stdio.h>

void handler(int signum)
{
    static char a;
    static int i;

    a = 0;
    i = 0;
    if(i > 7)
    {
        ft_printf("%c", a);
        i = 0;
    }
    a = a << 1;
    if(signum == 1)
        a = a + 1;
    i++;
}


int main(void)
{
    struct sigaction sa;

    sa.sa_handler = handler;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    
    ft_printf("PID: %i", getpid());
    while(1)
        pause();

}
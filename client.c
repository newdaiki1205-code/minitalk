#include "minitalk.h"


int	ft_atoi(const char *nptr)
{
	int	res;
	int	sign;

	res = 0;
	sign = 1;
	while (*nptr == 32 || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			sign *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		res = res * 10 + (*nptr - '0');
		nptr++;
	}
	return (res * sign);
}

int bit_op(unsigned char uc, int count)
{
    unsigned char a;

    if(count == 8)
      return -1;
    a = uc & (128 >> count);
    a = a >> (7 - count);
    return a;
}

void send_signal(char *str, pid_t pid)
{
  int i;
  int j;
  int bit;
  
  i = 0;
  while(str[i])
    {
      j = 0;
      while(j < 8)
      {
        bit = bit_op(str[i], j);
        if(bit == 1)
          kill(pid, SIGUSR1);
        else
          kill(pid, SIGUSR2);
        j++;
        usleep(100);
      }
      i++;
    }
}

int main(int ac, char **av)
{
    pid_t pid;
    
    if(ac != 3)
      return 1;
    pid = ft_atoi(av[1]);
    send_signal(av[2], pid);
    return 0;
}


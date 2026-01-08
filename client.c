#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


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

int test_bit(unsigned char uc, int count)
{
    unsigned char a;

    if(count == 8)
      return -1;
    a = uc & (128 >> count);
    a = a >> (7 - count);
    return a;
}


int main(int ac, char **av)
{
    int i;
    int j;
    int bit;
    __pid_t pid;
    
    if(ac != 3)
      return 1;
    pid = ft_atoi(av[1]);
    //printf("%d\n", pid);
    i = 0;
    while(av[2][i])
    {
      j = 0;
      while(j < 8)
      {
        bit = test_bit(av[2][i], j);
        if(bit == 1)
          //printf("%d", bit);
          kill(pid, SIGUSR1);
        else
          //printf("%d", bit);
          kill(pid, SIGUSR2);
        j++;
      }
      //printf("\n");  
      i++;
    }
    return 0;
}

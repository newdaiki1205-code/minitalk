#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void test_bit(unsigned char uc)
{
    int i;
    unsigned char a;
    unsigned char re;

    i = 0;
    re = 0;
    while(i < 8)
    {
        re = re << 1;
        a = uc & (128 >> i);
        a = a >> (7 - i);
        re += a;
        //printf("%d", a);
        i++;
    }
    //printf("\n");
    printf("%c", re);
}


int main(int ac, char **av)
{
    // unsigned char s[] = "Hello";
    int i = 0;
    
    while(av[1][i])
    {
        test_bit(av[1][i]);
        //printf("\n");
        i++;
    }
    return 0;
}
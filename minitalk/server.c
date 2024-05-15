#include "minitalk.h"

void data_handler(int sig)
{
    static int i;
    static char a;

    if(sig == SIGUSR1)
        a = (a << 1) | 1;
    else if(sig == SIGUSR2)
        a = (a << 1);
    i++;
    if(i == 8)
    {
        ft_printf("%c", a);
        i = 0;
        a = 0;
    }
}

int main()
{
    int PID;
    
    PID = getpid();
    ft_printf("Server online.\n PID -> %d\n", PID);
    signal(SIGUSR1, data_handler);
    signal(SIGUSR2, data_handler);
    while(1)
        pause();
}

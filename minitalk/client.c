#include "minitalk.h"


int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

void    data_sender(char a, int PID)
{
    int i;

    i = 0;
    while(i < 8)
    {
        if((a << i) & 128)
            kill(PID, SIGUSR1);
        else
            kill(PID, SIGUSR2);
        i++;
        usleep(100);
    }
}

int main(int ac, char *argv[])
{
    int PID;
    int i;

    i = 0;
    if(ac == 3)
    {
        PID = ft_atoi(argv[1]);
        while(argv[2][i])
            data_sender(argv[2][i++], PID);
    }
    else
        ft_printf("Wrong Format!\nUsage: ./client <PID> <MESSAGE>\n");
}

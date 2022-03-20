#include "minitalk.h"

int	send_messadge(int pid, char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 128;
		while (j)
		{
			if (str[i] & j)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			j = j >> 1;
			usleep(100);
		}
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
	{
		ft_putstr_fd("Usage: ./client [server PID] [text]\n", 2);
		return (1);
	}
	pid = ft_atoi_unsigned(argv[1]);
	if (pid < 0)
	{
		ft_putstr_fd("PID should be a positive number\n", 2);
		return (1);
	}	
	send_messadge(pid, argv[2]);
	return (0);
}

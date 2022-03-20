#include "minitalk.h"

void	get_signal(int sig)
{
	if (sig == SIGUSR1)
	{
		my_char.c += my_char.buf;
		my_char.buf = my_char.buf >> 1;
	}
	else
		my_char.buf = my_char.buf >> 1;
	if (!my_char.buf)
	{
		ft_putchar_fd(my_char.c, 1);
		my_char.buf = 128;
		my_char.c = 0;
	}
}

int	main()
{
	int	pid;

	pid = getpid();
	ft_putstr_fd("The server is runnung. PID is ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n", 1);
	my_char.buf = 128;
	my_char.c = 0;
	while (1)
	{
		signal(SIGUSR1, get_signal);
		signal(SIGUSR2, get_signal);
		pause();
	}
	return (0);
}

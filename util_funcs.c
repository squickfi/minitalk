#include "minitalk.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putstr_fd(char *s, int fd)
{
	size_t	count;

	count = 0;
	if (s)
	{
		while (s[count])
		{
			ft_putchar_fd(s[count], fd);
			count++;
		}
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = -n;
		}
		if (n / 10 != 0)
			ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
}

static int	ft_isspace(char c)
{
	if (c == '\n' || c == '\t' || c == '\r' || c == '\v' || c == '\f' || c == ' ')
		return (1);
	return (0);
}

int	ft_atoi_unsigned(const char *str)
{
	size_t	num;
	int		count;

	count = 0;
	num = 0;
	while (ft_isspace(str[count]))
		count++;
	if (str[count] == '-')
		return (-1);
	if (str[count] == '+')
		count++;
	while (str[count] >= '0' && str[count] <= '9')
	{
		num *= 10;
		num += str[count] - '0';
		count++;
	}
	if (str[count])
		return (-1);
	return (num);
}

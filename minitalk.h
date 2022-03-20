#ifndef MINITALK_H
# define MINITALK_H

# include <signal.h>
# include <unistd.h>

// libft_funcs.c

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_atoi_unsigned(const char *str);

typedef struct s_my_char
{
	int	buf;
	int	c;
}		t_my_char;

t_my_char	my_char;

#endif
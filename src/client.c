#include "minitalk.h"
#include "../libft/libft.h"
void	send_char(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c & 1)
		{
			kill(pid, SIGUSR1);
		}
		else
		{
			kill(pid, SIGUSR2);
		}
		c >>= 1;
		usleep(100);
		i++;
	}
}

int	main(int argc, char const *argv[])
{
	int	pid;

	if (argc != 3)
	{
		ft_printf("Usage: ./client [pid] [message]\n");
		return 1;
	}
	pid = ft_atoi(argv[1]);
	while (*argv[2])
	{
		send_char(pid, *argv[2]);
		argv[2]++;
	}
	send_char(pid, '\n');
	return 0;
}

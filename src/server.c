#include "minitalk.h"

void	handler(int signum)
{
	if (signum == SIGUSR1)
	{
		ft_printf(1);
	}
	else if (signum == SIGUSR2)
	{
		ft_printf(0);
	}

}

int	main(void)
{
	ft_putnbr(getpid());
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
	{
		usleep(100);
	}
	return 0;
}

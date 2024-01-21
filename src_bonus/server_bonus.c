/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsayumi- <dsayumi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:44:28 by danielasayu       #+#    #+#             */
/*   Updated: 2024/01/21 14:57:20 by dsayumi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

void	print_as_binary(unsigned char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		ft_printf("%d", (c >> (7 - i)) & 1);
		i++;
	}
}

void	handler(int signum, siginfo_t *info, void *context)
{
	static unsigned char	c = 0;
	static int				i = 7;

	(void)context;
	c |= (signum == SIGUSR1) << i;
	if (--i == -1)
	{
		write(1, &c, 1);
		i = 7;
		c = 0;
	}
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handler;
	sa.sa_flags = SA_SIGINFO;
	ft_printf("PID: %d \n", getpid());
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
	{
		pause();
	}
	return (0);
}

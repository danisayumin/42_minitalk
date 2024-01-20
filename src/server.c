/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielasayuminitta <danielasayuminitta@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:44:28 by danielasayu       #+#    #+#             */
/*   Updated: 2024/01/20 18:44:40 by danielasayu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signum)
{
	static unsigned char	c = 0;
	static int				i = 0;

	c |= (signum == SIGUSR1);
	if (++i == 8)
	{
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
	else
	{
		c <<= 1;
	}
}

int	main(void)
{
	ft_printf("PID: %d \n",getpid());
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
	{
		usleep(100);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielasayuminitta <danielasayuminitta@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:44:48 by danielasayu       #+#    #+#             */
/*   Updated: 2024/01/20 18:44:54 by danielasayu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include "../libft/libft.h"
void	send_char(int pid, char c)
{
	int	i;
	int bin[8];

	i = 0;
	while (i < 7)
	{
		bin[i] = c % 2;
		c /= 2;
		i++;
	}
	while (i>=0)
	{
		if (bin[i] == 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(100);
		i--;
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
	//send_char(pid, '\n');
	return 0;
}

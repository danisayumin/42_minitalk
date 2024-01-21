/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielasayuminitta <danielasayuminitta@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/20 18:44:48 by danielasayu       #+#    #+#             */
/*   Updated: 2024/01/20 18:54:56 by danielasayu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int g_sig_received = 0;

void	sig_handler(int sig, siginfo_t *info, void *ucontext)
{
	(void)sig;
	(void)info;
	(void)ucontext;
	g_sig_received = 1;
}

void	send_char(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		g_sig_received = 0;
		if((c >> (7 - i)) & 1){
			kill(pid, SIGUSR1);
			ft_printf("1");
		}
		else{
			kill(pid, SIGUSR2);
			ft_printf("0");
		}
		while (g_sig_received != 1)
			usleep(100);
		i++;
	}
	ft_printf("\n");

}

int	main(int argc, char const *argv[])
{
	int	pid;

	struct sigaction	sa;
	sa.sa_sigaction = sig_handler;
	sa.sa_flags = SA_SIGINFO;

	sigaction(SIGUSR1, &sa, NULL);

	if (argc != 3)
	{
		ft_printf("Usage: ./client [pid] [message]\n");
		return (1);
	}
	pid = ft_atoi(argv[1]);
	while (*argv[2])
	{
		send_char(pid, *argv[2]);
		argv[2]++;
	}
	return (0);
}

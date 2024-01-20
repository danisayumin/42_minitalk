/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielasayuminitta <danielasayuminitta@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 22:23:14 by dsayumi-          #+#    #+#             */
/*   Updated: 2024/01/19 22:43:47 by danielasayu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_putnbr(int n)
{
	long int	i;
	int			j;

	j = 1;
	i = n;
	if (i < 0)
	{
		ft_putchar('-');
		i = -i;
		j++;
	}
	if (i >= 10)
		j += ft_putnbr(i / 10);
	ft_putchar(i % 10 + '0');
	return (j);
}

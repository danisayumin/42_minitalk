/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danielasayuminitta <danielasayuminitta@    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 20:13:22 by dsayumi-          #+#    #+#             */
/*   Updated: 2024/01/19 22:43:47 by danielasayu      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

int	ft_putstr(char *s)
{
	int	i;
	int	count;

	if (!s)
		return (ft_putstr("(null)"));
	i = 0;
	count = 0;
	while (i < ft_strlen(s))
	{
		write(1, &s[i], 1);
		i++;
		count++;
	}
	return (count);
}

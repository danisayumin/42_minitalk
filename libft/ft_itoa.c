/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsayumi- <dsayumi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/26 22:15:46 by dsayumi-          #+#    #+#             */
/*   Updated: 2023/06/04 12:53:30 by dsayumi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include   "libft.h"

static int	ft_numlen(int n)
{
	int	len;

	len = 1;
	while (n / 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			len;
	int			sign;
	long int	num;

	num = n;
	sign = 0;
	if (num < 0)
	{
		sign = 1;
		num *= -1;
	}
	len = ft_numlen(num);
	str = (char *)malloc(sizeof(char) * (len + sign + 1));
	if (!str)
		return (NULL);
	str[len + sign] = '\0';
	while (len--)
	{
		str[len + sign] = num % 10 + '0';
		num /= 10;
	}
	if (sign)
		str[0] = '-';
	return (str);
}

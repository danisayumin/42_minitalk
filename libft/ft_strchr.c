/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsayumi- <dsayumi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 20:25:45 by dsayumi-          #+#    #+#             */
/*   Updated: 2023/05/12 20:33:59 by dsayumi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	ch;
	char	*str;

	ch = (char)c;
	str = (char *)s;
	while (*str)
	{
		if (*str == ch)
			return (str);
		str++;
	}
	if (*str == ch)
		return (str);
	return (NULL);
}

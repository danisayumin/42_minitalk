/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsayumi- <dsayumi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 19:52:59 by dsayumi-          #+#    #+#             */
/*   Updated: 2023/05/26 22:22:40 by dsayumi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;
	unsigned char	val;

	val = (unsigned char)c;
	p = s;
	i = 0;
	while (i < n)
	{
		p[i] = val;
		i++;
	}
	return (s);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsayumi- <dsayumi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 20:34:16 by dsayumi-          #+#    #+#             */
/*   Updated: 2023/06/05 22:43:44 by dsayumi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s1;

	s1 = (char *)s + (ft_strlen(s) - 1);
	if ((char )c == '\0')
		return ((char *)s + ft_strlen(s));
	while (s1 >= s)
	{
		if (*s1 == (char) c)
			return (s1);
		s1--;
	}
	return (NULL);
}

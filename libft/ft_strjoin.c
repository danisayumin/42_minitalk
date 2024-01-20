/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsayumi- <dsayumi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 20:44:03 by dsayumi-          #+#    #+#             */
/*   Updated: 2023/06/06 19:43:38 by dsayumi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	size_t	len_s1;
	size_t	len_s2;
	int		i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2) + 1;
	new_str = malloc(sizeof(char) * (len_s1 + len_s2));
	if (!new_str)
		return (NULL);
	while (*s1)
	{
		new_str[i++] = *s1++;
	}
	while (*s2)
	{
		new_str[i++] = *s2++;
	}
	new_str[i] = '\0';
	return (new_str);
}

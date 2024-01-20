/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsayumi- <dsayumi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/22 21:01:04 by dsayumi-          #+#    #+#             */
/*   Updated: 2023/06/06 19:50:59 by dsayumi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	len_s;
	char	*substr;

	if (s == NULL)
		return (NULL);
	len_s = ft_strlen(s);
	if (!s)
		return (NULL);
	if (start > len_s)
		return (ft_strdup(""));
	if (start + len > len_s)
		len = len_s - start;
	substr = (char *)malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (NULL);
	ft_strlcpy(substr, s + start, len + 1);
	substr[len] = '\0';
	return (substr);
}

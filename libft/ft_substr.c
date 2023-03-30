/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 11:42:56 by nleggeri          #+#    #+#             */
/*   Updated: 2023/03/06 09:53:23 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*dst;
	size_t	size;

	size = ft_strlen(s);
	i = 0;
	if (!s)
		return (NULL);
	if (start > size)
		return (ft_strdup(""));
	if ((size - start) < len)
		dst = malloc(sizeof(char) * (size - start + 1));
	else
		dst = malloc(sizeof(char) * (len + 1));
	if (!dst)
		return (NULL);
	while (i < len && s[start])
	{
		dst[i] = s[start];
		i++;
		start++;
	}
	dst[i] = '\0';
	return (dst);
}

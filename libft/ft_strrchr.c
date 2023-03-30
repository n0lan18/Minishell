/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <marvin@42lausanne.ch>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 16:34:06 by nleggeri          #+#    #+#             */
/*   Updated: 2022/11/08 13:13:36 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*str;

	str = (char *)s;
	i = ft_strlen(s);
	if ((char)c == '\0')
		return (&(str[i]));
	while (i > 0 && str[i] != (char)c)
		i--;
	if (str[i] == (char)c)
		return (&(str[i]));
	else
		return (NULL);
}

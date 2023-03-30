/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 23:09:48 by nleggeri          #+#    #+#             */
/*   Updated: 2022/11/09 13:44:06 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (0);
		i++;
	}
	return (1);
}

char	*ft_strtrim(char const *s1, const char *set)
{
	int	j;
	int	i;

	i = 0;
	j = ft_strlen(s1) - 1;
	if (!s1 || !set)
		return (NULL);
	if (!*set || !*s1)
		return (ft_strdup(s1));
	while (ft_check(set, s1[i]) == 0)
		i++;
	while (ft_check(set, s1[j]) == 0)
		j--;
	return (ft_substr(s1, i, (j - i + 1)));
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/31 21:21:26 by nleggeri          #+#    #+#             */
/*   Updated: 2023/03/06 11:32:52 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(const char *s, char c)
{
	size_t	i;
	size_t	size;
	size_t	start;

	size = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		if (start != i)
			size++;
	}
	return (size);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	size;
	size_t	start;
	size_t	i;

	tab = malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!tab)
		return (NULL);
	size = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		if (start != i)
		{
			tab[size] = ft_substr(s, start, i - start);
			size++;
		}
	}
	tab[size] = NULL;
	return (tab);
}

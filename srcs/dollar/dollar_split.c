/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollar_split.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:59:03 by synicole          #+#    #+#             */
/*   Updated: 2023/06/05 17:59:05 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static size_t	count_word(const char *s)
{
	size_t	i;
	size_t	size;
	size_t	start;

	size = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == '$' && s[i])
			i++;
		start = i;
		while (s[i] != '$' && s[i])
			i++;
		if (start != i)
			size++;
	}
	return (size);
}

char	**ft_dollar_split(char const *s)
{
	char	**tab;
	size_t	size;
	size_t	start;
	size_t	i;

	tab = malloc(sizeof(char *) * (count_word(s) + 1));
	if (!tab)
		return (NULL);
	size = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == '$' && s[i])
			i++;
		start = i;
		while (s[i] != '$' && s[i])
			i++;
		if (start != i)bas
		{
			tab[size] = ft_substr(s, start, i - start);
			size++;
		}
	}
	tab[size] = NULL;
	return (tab);
}

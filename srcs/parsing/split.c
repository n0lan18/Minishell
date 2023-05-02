/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 20:08:04 by synicole          #+#    #+#             */
/*   Updated: 2023/05/02 20:08:06 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

static int	ft_count_words(const char *s)
{
	int	num_words;
	int	i;

	num_words = 0;
	i = 0;
	while (s[i])
	{
		if (ft_is_space(s[i]))
			while (ft_is_space(s[i]) && s[i])
				i++;
		else
			while (!ft_is_space(s[i]) && s[i])
				i++;
		num_words++;
	}
	return (num_words);
}

char	**ft_split_space(char const *s)
{
	char	**split_tab;
	int		start;
	int		i;
	int		j;

	split_tab = malloc(sizeof(char *) * (ft_count_words(s) + 1));
	if (!split_tab)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		start = i;
		if (ft_is_space(s[i]))
			while (ft_is_space(s[i]) && s[i])
				i++;
		else
			while (!ft_is_space(s[i]) && s[i])
				i++;
		if (start != i)
			split_tab[j++] = ft_substr(s, start, i - start);
	}
	split_tab[j] = 0;
	return (split_tab);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_space.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 20:08:04 by synicole          #+#    #+#             */
/*   Updated: 2023/05/02 20:08:06 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Creates a tab containing the split string.
 * @param char *s to be split
 * @param char **split_tab to be filled
 *
 * @return char **tab containing the split string
*/
static char	**ft_create_split_tab(char const *s, char **split_tab)
{
	int		start;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i])
	{
		start = i;
		if (ft_is_space(s[i]))
			i = ft_skip_spaces(s, i);
		else if (s[i] == '\'' || s[i] == '\"')
			i = ft_skip_quotes(s, i, s[i]);
		else
			while (!ft_is_space(s[i]) && !ft_is_quotes(s[i]) && s[i])
				i++;
		split_tab[j++] = ft_substr(s, start, i - start);
	}
	split_tab[j] = 0;
	return (split_tab);
}

/**
 * Splits a string into an array of strings,
 * using space and quotes as delimiters.
 * @param char *s string to be split
 *
 * @return char **tab containing the split string
*/
char	**ft_split_tokens(char const *s)
{
	char	**split_tab;

	split_tab = malloc(sizeof(char *) * (ft_count_words(s) + 1));
	if (!split_tab)
		return (NULL);
	return (ft_create_split_tab(s, split_tab));
}

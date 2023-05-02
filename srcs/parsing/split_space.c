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
 * Counts the number of words in a string,
 * using space and special characters as delimiters.
 * @param char *s string to be split
 *
 * @return int number of words in the string
 */
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
		else if (ft_is_special_char(s[i]))
		{
			num_words++;
			i++;
			continue ;
		}
		else
			while (!ft_is_space(s[i]) && s[i] && !ft_is_special_char(s[i]))
				i++;
		num_words++;
	}
	return (num_words);
}

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
			while (ft_is_space(s[i]) && s[i])
				i++;
		else if (ft_is_special_char(s[i]))
		{
			split_tab[j++] = ft_substr(s, i, 1);
			i++;
			continue ;
		}
		else
			while (!ft_is_space(s[i]) && s[i] && !ft_is_special_char(s[i]))
				i++;
		split_tab[j++] = ft_substr(s, start, i - start);
	}
	split_tab[j] = 0;
	return (split_tab);
}

/**
 * Splits a string into an array of strings, using space as a delimiter.
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

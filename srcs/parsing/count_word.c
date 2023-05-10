/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_word.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/06 16:40:11 by synicole          #+#    #+#             */
/*   Updated: 2023/05/06 16:40:14 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Skips the spaces in a string.
 * @param char *s string to be skipped
 * @param int i index of the string
 *
 * @return int index of the string
 */
int	ft_skip_spaces(const char *s, int i)
{
	while (ft_is_space(s[i]))
		i++;
	return (i);
}

/**
 * Skips the quotes in a string.
 * @param char *s string to be skipped
 * @param int i index of the string
 * @param char quote to be skipped
 *
 * @return int index of the string
 */
int	ft_skip_quotes(const char *s, int i, char quote)
{
	i++;
	while (s[i] != quote && s[i])
		i++;
	if (s[i] == quote)
		i++;
	return (i);
}

/**
 * Counts the number of words in a string,
 * using space and special characters as delimiters.
 * @param char *s string to be split
 *
 * @return int number of words in the string
 */
int	ft_count_words(const char *s)
{
	int	num_words;
	int	i;

	num_words = 0;
	i = 0;
	while (s[i])
	{
		if (ft_is_space(s[i]))
			i = ft_skip_spaces(s, i);
		else if (s[i] == '\'' || s[i] == '\"')
			i = ft_skip_quotes(s, i, s[i]);
		else
		{
			while (!ft_is_space(s[i]) && !ft_is_quotes(s[i]) && s[i])
				i++;
		}
		num_words++;
	}
	return (num_words);
}

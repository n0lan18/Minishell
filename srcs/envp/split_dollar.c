/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_dollar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 21:51:58 by synicole          #+#    #+#             */
/*   Updated: 2023/05/09 21:52:00 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Gets the number of splits needed for ft_split_dollar.
 *
 * Example: 12$3$4 -> 3
 *
 * @param str
 * @return
 */
static int	ft_num_dollars(const char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	if (str[i] != '$')
		num++;
	while (str[i])
	{
		if (str[i] == '$')
			num++;
		i++;
	}
	return (num);
}

/**
 * Extends ft_split_dollar
 *
 * @param char const *s string to be split
 * @param char **tab_dollars to be filled
 * @param int i
 * @param int j
*/
static char	**ft_split_dollar_ext(char const *s, char **tab_dollars, int i, int j)
{
	int		num_dollars;

	num_dollars = 0;
	if (s[i] != '$')
	{
		j = i;
		while (s[i] != '$')
			i++;
		tab_dollars[num_dollars++] = ft_substr(s, j, i - j);
	}
	while (s[i])
	{
		if (s[i] == '$')
		{
			j = i + 1;
			while (s[j] && s[j] != '$')
				j++;
			tab_dollars[num_dollars++] = ft_substr(s, i, j - i);
			i = j;
		}
		else
			i++;
	}
	tab_dollars[num_dollars] = NULL;
	return (tab_dollars);
}

/**
 * Splits a string into an array of strings,
 * using space and dollar as delimiters.
 *
 * Example: xx$aaa$$pp$?qq$dd -> xx, $aaa, $, $pp, $?, qq, $dd
 *
 * @param char *s string to be split
 *
 * @return char **tab containing the split string
*/
char	**ft_split_dollar(char *s)
{
	char	**tab_dollars;

	tab_dollars = malloc(sizeof(char *) * (ft_num_dollars(s) + 1));
	if (!tab_dollars)
		ft_exit(EXIT_FAILURE, "malloc error");
	return (ft_split_dollar_ext(s, tab_dollars, 0, 0));
}

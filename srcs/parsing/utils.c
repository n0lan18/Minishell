/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:33:42 by synicole          #+#    #+#             */
/*   Updated: 2023/05/02 19:33:44 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Checks if a given string contains only whitespace characters.
 * @param const char *s to check.
 *
 * @return int 1 if the string contains only whitespace characters, otherwise 0.
*/
int	ft_contains_only_space(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (!ft_is_space(s[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 * Checks if a given character is a whitespace character.
 * @param char c to check.
 *
 * @return int 1 if the character is a whitespace character, otherwise 0.
*/
int	ft_is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f')
		return (1);
	return (0);
}

int	ft_is_special_char(char c)
{
	int		i;

	i = 0;
	while (SPECIAL_CHARS[i])
	{
		if (c == SPECIAL_CHARS[i])
			return (1);
		i++;
	}
	return (0);
}

/**
 * Trims a given string by removing all whitespace characters at the beginning
 * and at the end of the string.
 * @param const char *str to trim.
 *
 * @return char * The trimmed string.
*/
char	*ft_trim_str(const char *str)
{
	int		start;
	int		end;
	char	*trimmed_str;

	start = 0;
	while (ft_is_space(str[start]))
		start++;
	end = (int)ft_strlen(str) - 1;
	while (ft_is_space(str[end]))
		end--;
	trimmed_str = ft_substr(str, start, end - start + 1);
	return (trimmed_str);
}

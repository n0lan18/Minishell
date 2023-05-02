/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 20:33:01 by synicole          #+#    #+#             */
/*   Updated: 2023/05/01 20:33:03 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

/**
 * Checks if a given string contains only whitespace characters.
 * @param const char *s The string to check.
 * @return int Returns 1 if the string contains only whitespace characters,
 * otherwise 0.
*/
int	ft_contains_only_space(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

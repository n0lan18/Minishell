/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:30:37 by synicole          #+#    #+#             */
/*   Updated: 2023/05/28 16:30:38 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Check if the quotes are closed.
 *
 * @param str
 * @param c
 * @param i
 *
 * @return 1 if the quotes are closed, 0 otherwise.
 */
static int	ft_quote_is_open(const char *str, char c, int *i)
{
	(*i)++;
	while (str[*i])
	{
		if (str[*i] == c)
		{
			(*i)++;
			return (0);
		}
		(*i)++;
	}
	return (1);
}

/**
 * Check if the quotes are closed.
 * @param str
 *
 * @return 1 if the quotes are closed, 0 otherwise.
 */
int	ft_quote_is_valid(char *str)
{
	int	i;
	int	open;

	i = 0;
	open = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"')
			open = ft_quote_is_open(str, str[i], &i);
		else
			i++;
	}
	if (open)
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_token.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nleggeri <nleggeri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 23:10:19 by nleggeri          #+#    #+#             */
/*   Updated: 2023/04/16 23:10:39 by nleggeri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Get the type of the token
 * @param str
 *
 * @return int
 */
int	ft_get_token_type(const char *str)
{
	if (ft_contains_only_space(str))
		return (E_SPACE);
	else
		return (E_STRING);
}

/**
 * Get the quote of the token
 * @param str
 *
 * @return int
 */
int	ft_get_token_quote(const char *str)
{
	if (str[0] == '\'')
		return (E_SINGLE_QUOTE);
	else if (str[0] == '"')
		return (E_DOUBLE_QUOTE);
	return (E_STRING);
}

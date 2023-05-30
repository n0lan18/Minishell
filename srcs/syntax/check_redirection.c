/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_redirection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: synicole <synicole@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:30:43 by synicole          #+#    #+#             */
/*   Updated: 2023/05/28 16:30:45 by synicole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

/**
 * Check if there is an error in the redirection.
 *
 * @param token
 *
 * @return 1 if there is an error, 0 otherwise.
 */
static int	ft_has_redirection_error(t_token *token)
{
	t_token	*cpy;

	cpy = token;
	while (cpy->next->type == E_SPACE)
	{
		cpy = cpy->next;
		if (cpy->next == NULL)
			return (1);
	}
	if (cpy->next->type != E_STRING)
		return (1);
	return (0);
}

/**
 * Check if the redirection is valid.
 *
 * @param token
 *
 * @return 1 if the redirection is valid, 0 otherwise.
 */
int	ft_redirection_is_valid(t_token *token)
{
	if ((token->redirection == E_INFILE || token->redirection == E_OUTFILE)
		&& token->next != NULL)
	{
		if (ft_has_redirection_error(token))
			return (0);
	}
	if ((token->redirection == E_INFILE || token->redirection == E_OUTFILE)
		&& token->next == NULL)
		return (0);
	if (token->redirection == E_APPEND && token->next != NULL)
	{
		if (ft_has_redirection_error(token))
			return (0);
	}
	if (token->redirection == E_APPEND && token->next == NULL)
		return (0);
	return (1);
}
